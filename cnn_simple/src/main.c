/******************************************************************************
 *
 * Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*
 * main.c: simple hdmi out application
 * by RD
 * 2015.08.04
 *
 */
#include <stdlib.h>
#include "sds_lib.h"
#include <stdio.h>
#include "mult_core.h"
#include "imx222.h"
#include "xspips.h"
#include "xgpiops.h"
#include "v3_rgbout.h"
#include "v3_rgbin.h"
#include "zoom.h"
#include "conv1.h"
#include "conv2.h"
#include "identi_cal.h"
#include "im.h"
#include "label_image.h"
#include "xil_cache.h"
#include "copy_buffer.h"


/* Definitions for peripheral PLDMA_RGBIN_0 */
#define XPAR_PLDMA_RGBIN_0_BASEADDR 0x40010000
#define XPAR_PLDMA_RGBIN_0_HIGHADDR 0x4001FFFF


/* Definitions for peripheral PLDMA_RGBOUT_0 */
#define XPAR_PLDMA_RGBOUT_0_BASEADDR 0x40020000	//v2.1 change to 0x4002_0000
#define XPAR_PLDMA_RGBOUT_0_HIGHADDR 0x4000FFFF

/* Definitions for peripheral PS7_SPI_0 */
#define XPAR_PS7_SPI_0_DEVICE_ID 0

unsigned int mrd_addr = XPAR_PLDMA_RGBOUT_0_BASEADDR;
unsigned int mwr_addr = XPAR_PLDMA_RGBIN_0_BASEADDR;


int main() {
	XSpiPs spips;
	XSpiPs_Config* spi_config;
	unsigned int Status;

	// use ps gpio emio to
	XGpioPs gpiops;
	XGpioPs_Config *ConfigPtrPS;
	ConfigPtrPS = XGpioPs_LookupConfig(0);
	XGpioPs_CfgInitialize(&gpiops, ConfigPtrPS, ConfigPtrPS->BaseAddr);
	XGpioPs_SetDirectionPin(&gpiops, 54, 1);
	XGpioPs_SetOutputEnablePin(&gpiops, 54, 1);
	XGpioPs_SetDirectionPin(&gpiops, 55, 1);
	XGpioPs_SetOutputEnablePin(&gpiops, 55, 1);
	XGpioPs_SetDirectionPin(&gpiops, 56, 1);
	XGpioPs_SetOutputEnablePin(&gpiops, 56, 1);
	XGpioPs_SetDirectionPin(&gpiops, 57, 1);
	XGpioPs_SetOutputEnablePin(&gpiops, 57, 1);

	XGpioPs_WritePin(&gpiops, 55, 0x1); 	//hdmi outout enable
	XGpioPs_WritePin(&gpiops, 56, 0x1); 	//led on
	XGpioPs_WritePin(&gpiops, 57, 0x0);	//cmos reset_n
	XGpioPs_WritePin(&gpiops, 57, 0x1);	//cmos reset_n

	Xil_DCacheDisable();

	/*init spi*/
	spi_config = XSpiPs_LookupConfig(XPAR_PS7_SPI_0_DEVICE_ID);
	Status = XSpiPs_CfgInitialize(&spips, spi_config, spi_config->BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	XSpiPs_Reset(&spips);
	XSpiPs_SetOptions(&spips,XSPIPS_MASTER_OPTION | XSPIPS_FORCE_SSELECT_OPTION);
	XSpiPs_SetClkPrescaler(&spips, XSPIPS_CLK_PRESCALE_32);
	XSpiPs_SetSlaveSelect(&spips, 0);
	// configure CMOS sensor
	initialIMX122(&spips);

	//to reset bayer2rgb after cmos config done
	XGpioPs_WritePin(&gpiops, 54, 0x1);		// cmos config done
	XGpioPs_WritePin(&gpiops, 54, 0x0);

	// initial pldma_rgbin
	char cmos_writing_index;
	unsigned int *pVideoBuffer;
	float tgt_img[3][32][32];

	//sds_alloc_non_cacheable
	unsigned int* pSrcBuffer0 = (unsigned int*) sds_alloc_non_cacheable(FRAME_HEIGHT * FRAME_WIDTH * sizeof(uint32_t));//hdmi
	//uint32_t *pSrcBuffer1 = (uint32_t*) sds_alloc(FRAME_HEIGHT * FRAME_WIDTH * sizeof(uint32_t));//hdmi
	unsigned int* pDstBuffer = (unsigned int*) sds_alloc_non_cacheable(2048 * 2048 * sizeof(uint32_t)*3);//cmos
	// initial rgbout dma user ip
	video_out_init(mrd_addr);
	// initial rgbin dma user ip
	video_in_init(mwr_addr, (unsigned int*)pDstBuffer, FRAME_WIDTH,FRAME_HEIGHT);;

	while (1) {
		cmos_writing_index = get_video_in_index(mwr_addr);
		if (cmos_writing_index == 0)
			cmos_writing_index = 2;
		else
			cmos_writing_index = cmos_writing_index - 1;

		set_video_in_index(mwr_addr, cmos_writing_index);

		pVideoBuffer = (unsigned int*)(pDstBuffer+(cmos_writing_index<<22));

		float rst1[conv1_K][conv1_I][conv1_J]={{{0,0,0}}};//need to be reset 0 every time?
		float rst2[conv2_K][conv2_I][conv2_J]={{{0,0,0}}};//need to be reset 0 every time?
		//float* rst2 = (float*) sds_alloc_non_cacheable(conv2_K * conv2_I * conv2_J * sizeof(float));//
		float result[10]={0};
		// resize 1080P to 32X32  - -||
		zoom(pVideoBuffer, tgt_img);
		//conv1
		conv1(tgt_img,rst1);
		//conv2
		conv2(rst1,rst2);
		//image process
		identi_cal((float*)rst2,result);
		//classification
		int item_class=0;
		int i;
		float Pmax = 1.0;
		for(i=0;i<10;i++)
		{
			if(result[i]>Pmax)
			{
				Pmax=result[i];
				item_class=i;
			}
		}
		//if(Pmax>5.0) printf("%s\n",label[item_class]);
		//printf("%s,%f\n",label[item_class],Pmax);
		for(i=0;i<64;i++) {
			memcpy(pVideoBuffer+1920*i,label_array[item_class]+128*i*4,128*4);
		}
		//memcpy(pSrcBuffer0,pVideoBuffer,FRAME_HEIGHT * FRAME_WIDTH * sizeof(uint32_t));
		copy_buffer(pVideoBuffer, pSrcBuffer0);
		video_out_start(mrd_addr,pSrcBuffer0);
		//video_out_start(mrd_addr,pVideoBuffer);
	}

	video_out_reset(mrd_addr);
	video_in_reset(mwr_addr);

	return 0;
}

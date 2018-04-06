/*
 * copy_buffer.c
 *
 *  Created on: 2018Äê3ÔÂ11ÈÕ
 *      Author: Lenovo
 */
#include "copy_buffer.h"

void copy_buffer(unsigned int * input , unsigned int * output){
	unsigned i,j;
	unsigned index;
	for(i=0;i<FRAME_HEIGHT;i++){
		for(j=0;j<FRAME_WIDTH;j++){
#pragma AP PIPELINE II = 1
			index=FRAME_WIDTH*i+j;
			output[index]=input[index];
		}
	}
}


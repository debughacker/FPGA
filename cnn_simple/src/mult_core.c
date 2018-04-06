/*
 * mult_core.c
 *
 *  Created on: 2018年3月11日
 *      Author: Lenovo
 */

#include "mult_core.h"

void mmult_kernel(float in_A[A_NROWS][A_NCOLS],
		float in_B[B_NROWS][B_NCOLS],
		float out_C[28*28]){
#pragma HLS INLINE self
#pragma HLS array_partition variable=in_A complete dim=2
#pragma HLS array_partition variable=in_B complete dim=2
	int i,j,x,y;
	for(i=0;i<28;i++){
		for(j=0;j<28;j++){
#pragma HLS PIPELINE
			float result =0;
			for(x=0;x<A_NROWS;x++){
#pragma HLS UNROLL
				for(y=0;y<A_NCOLS;y++){
					float product_term = in_A[x][y]*in_B[x+i][y+j];
					result += product_term;
				}
			}
			out_C[i*28+j]=result;
		}
	}
}


void mmult(float in_A[A_NROWS][A_NCOLS],
		float in_B[B_NROWS][B_NCOLS],
		float out_C[28*28]){
	int i,j;
	float a_buf[A_NROWS][A_NCOLS];
	float b_buf[B_NROWS][B_NCOLS];
	//把in_A数据存储到a_buf矩阵中
	for(i=0;i<A_NROWS;i++){
		for(j=0;j<A_NCOLS;j++){
#pragma HLS PIPELINE
			a_buf[i][j]=in_A[i][j];
		}
	}
	// 把in_B数据存储到b_buf矩阵中
	for(i=0;i<B_NROWS;i++){
			for(j=0;j<B_NCOLS;j++){
#pragma HLS PIPELINE
				b_buf[i][j]=in_B[i][j];
			}
	}
	//核心的矩阵卷积
	mmult_kernel(a_buf,b_buf,out_C);
}

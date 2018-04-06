/*
 * mult_core.h
 *
 *  Created on: 2018Äê3ÔÂ11ÈÕ
 *      Author: Lenovo
 */

#ifndef SRC_MULT_CORE_H_
#define SRC_MULT_CORE_H_
#define A_NROWS 5
#define A_NCOLS A_NROWS
#define B_NROWS 32
#define B_NCOLS B_NROWS

#pragma SDS data access_pattern(in_A:SEQUENTIAL,in_B:SEQUENTIAL,out_C:SEQUENTIAL)

void mmult(float in_A[A_NROWS][A_NCOLS],
		float in_B[B_NROWS][B_NCOLS],
		float out_C[28*28]);


#endif /* SRC_MULT_CORE_H_ */

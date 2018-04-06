/*
 * identi_cal.h
 *
 *  Created on: 2016Äê7ÔÂ11ÈÕ
 *      Author: Thinkpad-T440p
 */

#ifndef SRC_IDENTI_CAL_H_
#define SRC_IDENTI_CAL_H_

//

#pragma SDS data mem_attribute(input:PHYSICAL_CONTIGUOUS|NON_CACHEABLE, output:PHYSICAL_CONTIGUOUS)
#pragma SDS data access_pattern(input:SEQUENTIAL, output:SEQUENTIAL)
#pragma SDS data copy(input[0:18432],output[0:10])
#pragma SDS data sys_port(input: AFI)
void identi_cal(float* input,float* output);


#endif /* SRC_IDENTI_CAL_H_ */

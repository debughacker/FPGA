/*
 * conv1.h
 *
 *  Created on: 2018年3月7日
 *      Author: Lenovo
 */

#ifndef SRC_CONV1_H_
#define SRC_CONV1_H_
#define conv1_imX 32 //输入图像宽
#define conv1_imY 32 //输入图像高
#define conv1_K	32 //卷积核数量
#define conv1_C 3 //图像的通道数
#define conv1_X 5 //卷积核宽度
#define conv1_Y 5 //卷积核高度
#define conv1_I conv1_imX - conv1_X +1 //输出特征值的宽度
#define conv1_J conv1_imY - conv1_Y +1 //输出特征值的高度

void conv1(float im[conv1_C][conv1_imX][conv1_imY],float rst[conv1_K][conv1_I][conv1_J]);


#endif /* SRC_CONV1_H_ */

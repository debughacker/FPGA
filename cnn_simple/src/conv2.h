/*
 * conv2.h
 *
 *  Created on: 2018年3月9日
 *      Author: Lenovo
 */

#ifndef SRC_CONV2_H_
#define SRC_CONV2_H_

#define conv2_imX 28 //输入图像宽
#define conv2_imY 28 //输入图像高
#define conv2_K	32 //卷积核数量
#define conv2_C 32 //图像的通道数
#define conv2_X 5 //卷积核宽度
#define conv2_Y 5 //卷积核高度
#define conv2_I conv2_imX - conv2_X +1 //输出特征值的宽度
#define conv2_J conv2_imY - conv2_Y +1 //输出特征值的高度




#endif /* SRC_CONV2_H_ */

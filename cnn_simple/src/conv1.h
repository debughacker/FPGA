/*
 * conv1.h
 *
 *  Created on: 2018��3��7��
 *      Author: Lenovo
 */

#ifndef SRC_CONV1_H_
#define SRC_CONV1_H_
#define conv1_imX 32 //����ͼ���
#define conv1_imY 32 //����ͼ���
#define conv1_K	32 //���������
#define conv1_C 3 //ͼ���ͨ����
#define conv1_X 5 //����˿��
#define conv1_Y 5 //����˸߶�
#define conv1_I conv1_imX - conv1_X +1 //�������ֵ�Ŀ��
#define conv1_J conv1_imY - conv1_Y +1 //�������ֵ�ĸ߶�

void conv1(float im[conv1_C][conv1_imX][conv1_imY],float rst[conv1_K][conv1_I][conv1_J]);


#endif /* SRC_CONV1_H_ */

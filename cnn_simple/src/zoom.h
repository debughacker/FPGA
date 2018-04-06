/*
 * zoom.h
 *
 *  Created on: 2016Äê7ÔÂ8ÈÕ
 *      Author: Thinkpad-T440p
 */

#ifndef SRC_ZOOM_H_
#define SRC_ZOOM_H_

#define FRAME_HEIGHT 1080
#define FRAME_WIDTH	 1920

#define Src_H 1080
#define Src_W 1920
#define Dst_H 32
#define Dst_W 32

typedef struct RGB32{
	unsigned char rgbB;
	unsigned char rgbG;
	unsigned char rgbR;
	unsigned char rgbA;
}ARGB;		//James


//#pragma SDS data access_pattern(input:RANDOM)
//#pragma SDS data buffer_depth(input:1024)
void zoom(unsigned int input[1024], float tgt_img[3][32][32]);


#endif /* SRC_ZOOM_H_ */

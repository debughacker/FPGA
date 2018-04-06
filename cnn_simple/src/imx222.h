/*
 * imx222.h
 *
 *  Created on: 2016Äê3ÔÂ15ÈÕ
 *      Author: clevo
 */

#ifndef IMX222_H_
#define IMX222_H_
#include "xstatus.h"
#include "xspips.h"

#define IMX122_CHIP_ID1 02
#define IMX122_OUT_FS 15
#define IMX122_OUT_MODE	1080

int initialIMX122(XSpiPs* InstancePtr);
#endif /* IMX222_H_ */

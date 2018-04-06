/*
 * identi_cal.c
 *
 *  Created on: 2016Äê7ÔÂ11ÈÕ
 *      Author: Thinkpad-T440p
 */
#include "identi_cal.h"
#include "ip1_w.h"
/*
void ip1(float *in,float out[10])
{
#pragma AP INTERFACE ap_fifo port=in depth=18432

    int i,o;
    for(o=0;o<ip1_O;o++)
    {
#pragma AP PIPELINE II = 1
      for(i=0;i<ip1_I;i++)
       {
        	out[o]+=in[i]*ip1_w[o][i];
       }
       out[o]+=ip1_b[o];
    }
}
*/
void identi_cal(float* input, float* output)
{
    int i,j;
    for(i=0;i<ip1_O;i++)
    {
        for(j=0;j<ip1_I;j++)
        {
        	output[i]+=input[j]*ip1_w[i][j];
        }
        output[i]+=ip1_b[i];
    }
}
/*
unsigned int image_process(float* input,float* output)
{
//#pragma AP INTERFACE ap_fifo port=input depth=18432
//#pragma AP INTERFACE ap_fifo port=out depth=10
    int i,j,k,index,t;
    float temp=0;
    float temp1=0;
    float temp_sum=0;

    for(t=0;t<10;t++){
      for(i=0;i<32;i++)
    	  for(j=0;j<24;j++)
    		  for(k=0;k<24;k++){
#pragma AP PIPELINE
    			  index = i*24*24+j*24+k;
    			  temp = input[index];
    			  temp1= ip1_w[t][index];
#pragma AP inline
    			  temp_sum=temp_sum + temp*temp1;
    		  }
       //out[t]+=ip1_b[t];	//this will make out as "inout" port...so move it out of the function
      output[t] = temp_sum + ip1_b[t];
      temp_sum = 0;
    }
    return 0;
}

*/
/*
void image_process(float* input,float* input_param,float* output)
{
//#pragma AP INTERFACE ap_fifo port=input depth=18432
//#pragma AP INTERFACE ap_fifo port=out depth=10
    int i,t;
    float temp=0;
    float temp1=0;
    float temp_sum=0;

    for(t=0;t<10;t++){
      for(i=0;i<(32*24*24);i++) {
#pragma AP PIPELINE II = 1
    	temp = input[i];
    	temp1 = temp*ip1_w[t][i];
//#pragma AP inline
    	temp_sum += temp1;
      }
      output[t] = temp_sum + ip1_b[t];
      temp_sum = 0;
    }

}
*/

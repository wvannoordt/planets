#ifndef TRX_UTIL_H
#define TRX_UTIL_H

#define TRXMIN(a, b) (((a)>(b))?(b):(a))
#define TRXMAX(a, b) (((a)>(b))?(a):(b))
#define TRXABS(a) (((a)>(0))?(a):(-(a)))

#define color_blend(color1, color2, floatValue) \
    ((((int)((floatValue)*(((color2)&0x000000ff)>> 0) + (1.0-(floatValue))*((color1&0x000000ff)>> 0)))<< 0) |\
     (((int)((floatValue)*(((color2)&0x0000ff00)>> 8) + (1.0-(floatValue))*((color1&0x0000ff00)>> 8)))<< 8) |\
     (((int)((floatValue)*(((color2)&0x00ff0000)>>16) + (1.0-(floatValue))*((color1&0x00ff0000)>>16)))<<16))

#define MAX_DISTANCE 1e10

#endif
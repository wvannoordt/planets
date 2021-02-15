#ifndef TRX_UTIL_H
#define TRX_UTIL_H

#define TRXMIN(a, b) (((a)>(b))?(b):(a))
#define TRXMAX(a, b) (((a)>(b))?(a):(b))
#define TRXABS(a) (((a)>(0))?(a):(-(a)))

#define MAX_DISTANCE 1e10

#endif
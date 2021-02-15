#ifndef TRX_IMAGE_BUFFER_H
#define TRX_IMAGE_BUFFER_H
#include <iostream>
#include "ScreenBoundingBox.h"
namespace trx
{
    template <class bufType> struct ImageBuffer
    {
        bufType* data;
        int ni, nj;
        ImageBuffer(void)
        {
            ni = 0;
            nj = 0;
            data = NULL;
        }
        void SetSize(int ni_in, int nj_in)
        {
            if (data!= NULL) free(data);
            ni = ni_in;
            nj = nj_in;
            data = (bufType*)malloc(ni*nj*sizeof(bufType));
        }
        void SetSize(int ni_in, int nj_in, int elemCount)
        {
            if (data!= NULL) free(data);
            ni = ni_in;
            nj = nj_in;
            data = (bufType*)malloc(ni*nj*elemCount*sizeof(bufType));
        }
        
        void Fill(bufType val)
        {
            for (size_t i = 0; i < ni*nj; i++) data[i] = val;
        }
        
        ~ImageBuffer(void)
        {
            if (data != NULL) free(data);
            data = NULL;
        }
    };
}

#endif
#ifndef TRX_PNG_IMAGE_H
#define TRX_PNG_IMAGE_H

#include <string>
#include "PngCrc32.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "zlib.h"
#include <vector>
#include <assert.h>
#include <cstring>

namespace trx
{
    typedef unsigned char pxtype[4];
    
    class PngImage
    {
        public:
            PngImage(int height_in, int width_in, int* imageBuffer_in);
            PngImage(int height_in, int width_in);
            void Fill(int color);
            void Fill(pxtype color);
            void SetPixel(int row, int col, int color);
            void SetPixel(int row, int col, pxtype color);
            void AlphaSetPixel(int row, int col, int color);
            void AlphaSetPixel(int row, int col, pxtype color);
            ~PngImage(void);
            void Write(std::string filename);
            int* GetBuffer(void);
            int GetHeight(void);
            int GetWidth(void);
        
        private:
            void WriteSignature(FILE* fileWriter);
            void WriteHeader(FILE* fileWriter, const int& width, const int& height);
            void WriteData(FILE* fileWriter, const int& col, const int& row, int* imdata);
            void WriteEnd(FILE* fileWriter);
            void FlipEndianness(int* i);
            void CompressMemory(void *in_data, size_t in_data_size, std::vector<uint8_t> &out_data);
            int width;
            int height;
            int* imageBuffer;
            bool hasSelfContainedBuffer;
            bool bufferRequiresDealloc;
            bool machineIsBigEndian;
            PngCrc32 checksum;
    };
}

#endif
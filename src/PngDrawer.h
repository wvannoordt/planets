#ifndef PNG_DRAW_H
#define PNG_DRAW_H
#include "PngImage.h"
namespace trx
{
    class PngDrawer
    {
        public:
            PngDrawer(PngImage* image_in);
            ~PngDrawer(void);
            void Fill(int color);
            void Fill(pxtype color);
            void SetCoordinateSystem(double xmin_in, double xmax_in, double ymin_in, double ymax_in);
            void FillBox(double x0, double x1, double y0, double y1, int color);
            void FillBox(double x0, double x1, double y0, double y1, pxtype color);
            void OutlineBox(double x0, double x1, double y0, double y1, pxtype fillColor, pxtype borderColor, int borderWidth);
            void OutlineBox(double x0, double x1, double y0, double y1, int fillColor, pxtype borderColor, int borderWidth);
            void OutlineBox(double x0, double x1, double y0, double y1, pxtype fillColor, int borderColor, int borderWidth);
            void OutlineBox(double x0, double x1, double y0, double y1, int fillColor, int borderColor, int borderWidth);
            
        private:
            void CoordsToIndices(double x, double y, int* i, int* j);
            PngImage* image;
            int width;
            int height;
            double xmin;
            double xmax;
            double ymin;
            double ymax;
    };
}

#endif
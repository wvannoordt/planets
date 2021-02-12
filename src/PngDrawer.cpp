#include "PngDrawer.h"
#include "util.h"
namespace trx
{
    PngDrawer::PngDrawer(PngImage* image_in)
    {
        image = image_in;
        width = image->GetWidth();
        height = image->GetHeight();
        xmin = 0.0;
        xmax = (double)width;
        ymin = 0.0;
        ymax = (double)height;
    }
    
    PngDrawer::~PngDrawer(void)
    {
        
    }
    
    void PngDrawer::SetCoordinateSystem(double xmin_in, double xmax_in, double ymin_in, double ymax_in)
    {
        xmin = xmin_in;
        xmax = xmax_in;
        ymin = ymin_in;
        ymax = ymax_in;
    }
    
    void PngDrawer::CoordsToIndices(double x, double y, int* i, int* j)
    {
        *j = (int)((double)width *(x-xmin)/(xmax-xmin));
        *i = (int)((double)height*((ymax-y)-ymin)/(ymax-ymin));
    }
    
    void PngDrawer::Fill(int color) {image->Fill(color);}
    void PngDrawer::Fill(pxtype color) {image->Fill(color);}
    
    void PngDrawer::FillBox(double x0, double x1, double y0, double y1, pxtype color)
    {FillBox(x0, x1, y0, y1, *((int*)color));}
    void PngDrawer::FillBox(double x0, double x1, double y0, double y1, int color)
    {
        int ilow, ihigh, jlow, jhigh;
        int i1, i2, j1, j2;
        CoordsToIndices(x0, y0, &i1,  &j1);
        CoordsToIndices(x1, y1, &i2, &j2);
        ilow  = TRXMIN(i1, i2);
        ihigh = TRXMAX(i1, i2);
        jlow  = TRXMIN(j1, j2);
        jhigh = TRXMAX(j1, j2);
        
        for (int i = ilow; i < ihigh; i++)
        {
            if (i < height && i >= 0)
            {
                for (int j = jlow; j < jhigh; j++)
                {
                    if (j < width && j >= 0)
                    {
                        image->AlphaSetPixel(i, j, color);
                    }
                }
            }
        }
    }
    
    void PngDrawer::OutlineBox(double x0, double x1, double y0, double y1, pxtype fillColor, pxtype borderColor, int borderWidth)
    {OutlineBox(x0, x1, y0, y1, *((int*)fillColor), *((int*)borderColor), borderWidth);}
    void PngDrawer::OutlineBox(double x0, double x1, double y0, double y1, int fillColor, pxtype borderColor, int borderWidth)
    {OutlineBox(x0, x1, y0, y1, fillColor, *((int*)borderColor), borderWidth);}
    void PngDrawer::OutlineBox(double x0, double x1, double y0, double y1, pxtype fillColor, int borderColor, int borderWidth)
    {OutlineBox(x0, x1, y0, y1, *((int*)fillColor), borderColor, borderWidth);}
    void PngDrawer::OutlineBox(double x0, double x1, double y0, double y1, int fillColor, int borderColor, int borderWidth)
    {
        int ilow, ihigh, jlow, jhigh;
        int i1, i2, j1, j2;
        CoordsToIndices(x0, y0, &i1,  &j1);
        CoordsToIndices(x1, y1, &i2, &j2);
        ilow  = TRXMIN(i1, i2);
        ihigh = TRXMAX(i1, i2);
        jlow  = TRXMIN(j1, j2);
        jhigh = TRXMAX(j1, j2);
        for (int i = ilow; i < ihigh; i++)
        {
            if (i < height && i >= 0)
            {
                for (int j = jlow; j < jhigh; j++)
                {
                    int colorToDraw = fillColor;
                    if (TRXMIN(TRXMIN(i-ilow,ihigh-1-i),TRXMIN(j-jlow,jhigh-1-j))<borderWidth) colorToDraw=borderColor;
                    if (j < width && j >= 0)
                    {
                        image->AlphaSetPixel(i, j, colorToDraw);
                    }
                }
            }
        }
    }
}
#ifndef TRX_SCREEN_BOUND_BOX_H
#define TRX_SCREEN_BOUND_BOX_H

namespace trx
{
    struct ScreenBoundingBox
    {
        int imin;
        int jmin;
        int imax;
        int jmax;
    };
}

#endif
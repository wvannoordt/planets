#ifndef TRX_VOPS_H
#define TRX_VOPS_H

#include <cmath>

#define v_dot(a, b) (((*(a)) * (*(b))) + ((*((a)+1)) * (*((b)+1))) + ((*((a)+2)) * (*((b)+2))))
#define v_normsq(a) v_dot((a), (a))
#define v_norm(a) sqrt(v_normsq((a)))


#endif
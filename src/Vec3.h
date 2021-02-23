#ifndef TRX_VEC3_H
#define TRX_VEC3_H
#include <iostream>
#include <cmath>
namespace trx
{
    struct Vec3
    {
        Vec3(void) {v[0] = 0.0; v[1] = 0.0; v[2] = 0.0;}
        Vec3(double x, double y, double z) {v[0] = x; v[1] = y; v[2] = z;}
        Vec3(double* x) {v[0] = x[0]; v[1] = x[1]; v[2] = x[2];}
        Vec3(double* ini, double* ter) {v[0] = ter[0]-ini[0]; v[1] = ter[1]-ini[1]; v[2] = ter[2]-ini[2];}
        Vec3(const Vec3& w) {v[0] = w.v[0]; v[1] = w.v[1]; v[2] = w.v[2];}
        double v[3];
        
        void Normalize(void)
        {
            double norm = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
            v[0]/=norm;
            v[1]/=norm;
            v[2]/=norm;
        }
        Vec3 operator + (const Vec3& w) {return Vec3(v[0]+w.v[0], v[1]+w.v[1], v[2]+w.v[2]);}
        Vec3 operator - (const Vec3& w) {return Vec3(v[0]-w.v[0], v[1]-w.v[1], v[2]-w.v[2]);}
        Vec3 operator % (const Vec3& w) {return Vec3(v[1]*w.v[2] - v[2]*w.v[1], v[2]*w.v[0] - v[0]*w.v[2], v[0]*w.v[1] - v[1]*w.v[0]);}
        Vec3 operator * (const double a) {return Vec3(a*v[0], a*v[1], a*v[2]);}
        Vec3 operator / (const double a) {return Vec3(v[0]/a, v[1]/a, v[2]/a);}
        double operator * (const Vec3& w) {return v[0]*w.v[0] + v[1]*w.v[1] + v[2]*w.v[2];}
        double Norm(void) {return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);}
    };
    static std::ostream & operator<<(std::ostream & os, const Vec3 & vec)
    {
       os << "[" << vec.v[0] << ", " << vec.v[1] << ", " << vec.v[2] << "]";
       return os;
    }
}

#endif
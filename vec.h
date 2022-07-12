//
// Created by Kira_ on 2022/7/12.
//

#ifndef SMALLPT_VEC_H
#define SMALLPT_VEC_H

#include <cmath>

struct Vec
{
    double x, y, z;

    explicit Vec(double x_ = 0, double y_ = 0, double z_ = 0)
        : x(x_), y(y_), z(z_) {}

    // operator overload
    Vec operator+(const Vec& b) const { return Vec{x + b.x, y + b.y, z + b.z}; }
    Vec operator-(const Vec& b) const { return Vec{x - b.x, y - b.y, z - b.z}; }
    Vec operator*(const double b) const { return Vec{b * x, b * y, b * z}; }
    Vec operator%(const Vec& b) const { return Vec{y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.z}; }

    // funciton
    Vec mult (const Vec& b) const { return Vec{x * b.x, y * b.y, z * b.z}; }
    Vec cross(const Vec& b) const { return this->operator%(b); }
    double length() { return sqrt(x * x + y * y + z * z); }
    Vec& norm() { return *this = *this * (1 / length()); }
    double dot(const Vec& b) { return x * b.x + y * b.y + z * b.z; }


};

using Point = Vec;
using Color = Vec;

#endif //SMALLPT_VEC_H

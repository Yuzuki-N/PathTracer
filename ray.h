//
// Created by Kira_ on 2022/7/12.
//

#ifndef SMALLPT_RAY_H
#define SMALLPT_RAY_H

#include "vec.h"

struct Ray
{
    Point o;
    Vec d;

    Ray(Point o_, Vec d_) : o(o_), d(d_) {}

};

#endif //SMALLPT_RAY_H

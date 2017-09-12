#pragma once
#include <iostream>
#include "math.hpp"

class Vec4{

public:

// Constructeurs, Destructeur

    Vec4(void);
    Vec4(Vec4 const & src);
    Vec4(float x, float y, float z, float w);
    Vec4(Vec3 const & src, float w);
    Vec4(Vec3 const & src);
    virtual ~Vec4(void);
    Vec4 & operator=(Vec4 const & src);


// variables

    float x;
    float y;
    float z;
    float w;

// functions

    Vec4 operator+(Vec4 const & src) const;

};

std::ostream & operator<<(std::ostream & o, Vec4 const & i);
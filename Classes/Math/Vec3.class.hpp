#pragma once
#include <iostream>
#include "math.hpp"

class Vec3{

public:

// Constructeurs, Destructeur

    Vec3(void);
    Vec3(Vec3 const & src);
    Vec3(Vec4 const & src);
    Vec3(float x, float y, float z);
    Vec3(Vec2 const & src, float z);
    virtual ~Vec3(void);
    Vec3 & operator=(Vec3 const & src);
    Vec3 & operator=(Vec4 const & src);


// variables

    float x;
    float y;
    float z;

// functions

    Vec3 operator+(Vec3 const & src) const;

};

std::ostream & operator<<(std::ostream & o, Vec3 const & i);
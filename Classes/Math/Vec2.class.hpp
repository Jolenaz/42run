#pragma once
#include <iostream>
#include "math.hpp"

class Vec2{

public:

// Constructeurs, Destructeur

    Vec2(void);
    Vec2(Vec2 const & src);
    Vec2(float x, float y);
    virtual ~Vec2(void);
    Vec2 & operator=(Vec2 const & src);


// variables

    float x;
    float y;

// functions

    Vec2 operator+(Vec2 const & src) const;

};

std::ostream & operator<<(std::ostream & o, Vec2 const & i);
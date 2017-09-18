#pragma once
#include "joMath.hpp"

class Vertex{

    //constrcutor

    public:

    Vertex(void);
    Vertex(Vec3 pos, Vec3 norm, Vec2 text);
    ~Vertex(void);
    Vertex(Vertex const &);
    Vertex & operator=(Vertex const &);

    //atribute

    Vec3 pos;
    Vec3 normal;
    Vec2 uv;

};

std::ostream & operator<<(std::ostream & o, Vertex const & i);
#pragma once
#include "joMath.hpp"

class Vertex{

    //constrcutor

    public:

    Vertex(void);
    Vertex(Vec3 pos, Vec3 norm, Vec2 text);
    Vertex(Vec3 pos, Vec2 text, Vec3 norm);
    ~Vertex(void);
    Vertex(Vertex const &);
    Vertex & operator=(Vertex const &);

    //atribute

    Vec3 pos;
    Vec2 uv;
    Vec3 normal;

};

std::ostream & operator<<(std::ostream & o, Vertex const & i);
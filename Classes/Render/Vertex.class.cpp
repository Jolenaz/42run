#include "Vertex.class.hpp"

Vertex::Vertex(void){}
Vertex::Vertex(Vec3 pos, Vec3 norm, Vec2 text){
    this->pos = pos;
    this->normal = norm;
    this->uv = text;
}
Vertex::Vertex(Vec3 pos, Vec2 text, Vec3 norm){
    this->pos = pos;
    this->normal = norm;
    this->uv = text;
}
Vertex::~Vertex(void){}
Vertex::Vertex(Vertex const & src){
    this->pos = src.pos;
    this->normal = src.normal;
    this->uv = src.uv;
}
Vertex & Vertex::operator=(Vertex const & rhs){
    this->pos = rhs.pos;
    this->normal = rhs.normal;
    this->uv = rhs.uv;
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Vertex const & i){
    o << i.pos << " " << i.uv << " " << i.normal;
    return o;
}
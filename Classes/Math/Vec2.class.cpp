#include "Vec2.class.hpp"

Vec2::Vec2(void) : x(0.0f) , y(0.0f){}

Vec2::Vec2(Vec2 const & src): x(src.x) , y(src.y){}

Vec2::Vec2(float x, float y): x(x) , y(y){}

Vec2::~Vec2(void){}

Vec2 & Vec2::operator=(Vec2 const & rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

Vec2 Vec2::operator+(Vec2 const & rhs) const{
    return Vec2(this->x + rhs.x, this->y + rhs.y);
}

std::ostream & operator<<(std::ostream & o, Vec2 const & i){
    o << "( " << i.x << " , " << i.y << " )";
    return o;
}
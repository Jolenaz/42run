#include "Vec3.class.hpp"

Vec3::Vec3(void) : x(0.0f), y(0.0f), z(0.0f){}

Vec3::Vec3(Vec3 const & src): x(src.x), y(src.y), z(src.z){}

Vec3::Vec3(Vec4 const & src){
    this->x = src.w == 0 ? src.x : src.x / src.w;
    this->y = src.w == 0 ? src.y : src.y / src.w;
    this->z = src.w == 0 ? src.z : src.z / src.w;
}

Vec3::Vec3(Vec2 const & src, float z): x(src.x), y(src.y), z(z){}

Vec3::Vec3(float x, float y, float z): x(x), y(y), z(z){}

Vec3::~Vec3(void){}

Vec3 & Vec3::operator=(Vec3 const & rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    return *this;
}

Vec3 & Vec3::operator=(Vec4 const & rhs){
    this->x = rhs.w == 0 ? rhs.x : rhs.x / rhs.w;
    this->y = rhs.w == 0 ? rhs.y : rhs.y / rhs.w;
    this->z = rhs.w == 0 ? rhs.z : rhs.z / rhs.w;
    return *this;
}

Vec3 Vec3::operator+(Vec3 const & rhs) const{
    return Vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

std::ostream & operator<<(std::ostream & o, Vec3 const & i){
    o << "( " << i.x << " , " << i.y << " , " << i.z << " )";
    return o;
}
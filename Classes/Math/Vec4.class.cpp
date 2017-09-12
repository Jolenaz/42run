#include "Vec4.class.hpp"

Vec4::Vec4(void) : x(0.0f), y(0.0f), z(0.0f), w(0.0f){}

Vec4::Vec4(Vec4 const & src): x(src.x), y(src.y), z(src.z), w(src.w){}

Vec4::Vec4(Vec3 const & src, float w): x(src.x), y(src.y), z(src.z), w(w){}

Vec4::Vec4(Vec3 const & src): x(src.x), y(src.y), z(src.z), w(1.0f){
    std::cout << "utilisation dangeureuse, preciser la valeur de w" << std::endl;
}

Vec4::Vec4(float x, float y, float z, float w): x(x), y(y), z(z), w(w){}

Vec4::~Vec4(void){}

Vec4 & Vec4::operator=(Vec4 const & rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    this->w = rhs.w;
    return *this;
}

Vec4 Vec4::operator+(Vec4 const & rhs) const{
    return Vec4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

std::ostream & operator<<(std::ostream & o, Vec4 const & i){
    o << "( " << i.x << " , " << i.y << " , " << i.z << " , " << i.w << " )";
    return o;
}
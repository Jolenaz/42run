#include "Camera.class.hpp"

Camera::Camera(){
    this->_fov = 50;
    this->_near = 1;
    this->_far = 100;
    this->_ratio = 4.0f / 3.0f;
}

Camera::Camera(float fov, float near, float far, float ratio): _fov(fov), _near(near), _far(far), _ratio(ratio){}

Camera::~Camera(){}

Camera::Camera(Camera const & src)
{
    this->_fov =   src.get_fov();
    this->_near =  src.get_near();
    this->_far =   src.get_far();
    this->_ratio = src.get_ratio();
}

void Camera::calcProjection()
{

    float tanFov = tanf(this->_fov / 2.0f * M_PI / 180.0f);

    this->projMat.set_identity();
    this->projMat.value.m00 = 1.0f / (this->_ratio * tanFov);
    // this->projMat.value.m00 = ;
    // this->projMat.value.m00 = ;
    // this->projMat.value.m00 = ;
    // this->projMat.value.m00 = ;
    // this->projMat.value.m00 = ;
    // this->projMat.value.m00 = ;
}

float     Camera::get_fov() const{ return (this->_fov); }
float     Camera::get_near() const{ return (this->_near); }
float     Camera::get_far() const{ return (this->_far); }
float     Camera::get_ratio() const{ return (this->_ratio); }
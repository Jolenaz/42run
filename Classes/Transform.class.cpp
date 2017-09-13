
#include "Transform.class.hpp"

Transform::Transform(){
    this->position = Vec3(0,0,0);
    this->rotation = Vec3(0,0,0);
    this->scale = Vec3(1,1,1);
    this->parent = NULL;
    
}

Transform::Transform(Vec3 pos, Vec3 rot, Vec3 scale): position(pos), rotation(rot), scale(scale) {
    this->parent = NULL;
}

Transform::~Transform(){}

void Transform::translate(Vec3 const & trans)
{
    this->position += trans;
    this->_updateMatrix();
}

void Transform::rotate(Vec3 const & rot)
{
    this->rotation += rot;
    this->_updateMatrix();
}

void Transform::scalate(Vec3 const & scale)
{
    this->scale.x *= scale.x;
    this->scale.y *= scale.y;
    this->scale.z *= scale.z;
    this->_updateMatrix();
}

void Transform::_updateMatrix()
{
    this->worldToLocal.set_identity().scale(this->scale).rotateLocal(this->rotation).translate(this->position);

    if (this->parent != NULL)
        this->worldToLocal = this->worldToLocal * this->parent->worldToLocal;
}
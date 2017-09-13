#pragma once
#include "42run.hpp"


class Transform;

class Camera{
    public:

    // Constructeurs, Destructeur

    Camera(void);
    Camera(float fov, float near, float far, float ratio);
    Camera(Camera const & src);
    virtual ~Camera(void);
    Camera & operator=(Camera const & src);

    Mat4 projMat;

    float     get_fov() const;
    float     get_near() const;
    float     get_far() const;
    float     get_ratio() const;

    // attribus
    private:

    float     _fov;
    float     _near;
    float     _far;
    float     _ratio;
    Transform _transform;






    void    calcProjection();



    // fonctions membres

    // fonctions non membres
};
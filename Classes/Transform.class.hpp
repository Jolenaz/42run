
#pragma once
#include "joMath.hpp"

class Transform{
    public:

    // Constructeurs, Destructeur

    Transform(void);
    Transform(Vec3 pos, Vec3 rot, Vec3 scale);
    Transform(Transform const & src);
    virtual ~Transform(void);
    Transform & operator=(Transform const & src);

    // attribus

    Vec3 position;
    Vec3 rotation;
    Vec3 scale;
    Mat4 worldToLocal;

    Transform * parent;


    // fonctions membres

    void translate(Vec3 const & trans);
    void rotate(Vec3 const & rot);
    void scalate(Vec3 const & scale);

    private:

    void    _updateMatrix();


    // fonctions non membres
};
#pragma once
#include "GameObject.class.hpp"

class Player : public GameObject{

    public:
    virtual ~Player(void);
    Player(Camera * cam);

    Player(void);
    Player(Player const &);
    Player & operator=(Player const &);

    Camera * cam;

};
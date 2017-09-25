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

    void move_right ( void );
    void move_left ( void );

    private:

    int _rail; 

};
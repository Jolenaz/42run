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

    int rail;

    void jump(void);
    void update(float delta);

    bool    jumping;
    
    private:

    bool    moving_right;
    bool    moving_left;
    float   lateral_speed;
    Vec3    init_pos;
    float   vertical_speed;

};
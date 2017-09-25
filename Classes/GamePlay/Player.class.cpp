#include "Player.class.hpp"

Player::Player(Camera * cam) : GameObject(){
    this->cam = cam;
    this->meshName = "test";
    this->transform.scalate(Vec3(0.2,0.2,0.2));
    this->transform.translate(Vec3(0,-0.5,-1.2));
    this->rail = 1;
}

Player::~Player(){}


void Player::move_right ( void ){
    if (this->rail < 2)
    {
        this->rail += 1;
        this->transform.translate(Vec3(1,0,0));
        this->cam->transform.translate(Vec3(1,0,0));
    }
}

void Player::move_left ( void ){
    if (this->rail > 0)
    {
        this->rail -= 1;
        this->transform.translate(Vec3(-1,0,0));
        this->cam->transform.translate(Vec3(-1,0,0));
    }
}
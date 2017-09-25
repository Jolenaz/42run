#include "Player.class.hpp"

Player::Player(Camera * cam) : GameObject(){
    this->cam = cam;
    this->meshName = "player";
    this->_rail = 1;
}

Player::~Player(){}


void Player::move_right ( void ){
    if (this->_rail < 2)
    {
        this->_rail += 1;
        this->transform.translate(Vec3(1,0,0));
        this->cam->transform.translate(Vec3(1,0,0));
    }
}

void Player::move_left ( void ){
    if (this->_rail > 0)
    {
        this->_rail -= 1;
        this->transform.translate(Vec3(-1,0,0));
        this->cam->transform.translate(Vec3(-1,0,0));
    }
}
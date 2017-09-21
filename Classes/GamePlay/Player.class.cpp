#include "Player.class.hpp"

Player::Player(Camera * cam) : GameObject(){
    this->cam = cam;
    this->meshName = "player";
}

Player::~Player(){}

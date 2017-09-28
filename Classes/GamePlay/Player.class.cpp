#include "Player.class.hpp"

Player::Player(Camera * cam) : GameObject(){
    this->cam = cam;
    this->meshName = "player";
    this->transform.scalate(Vec3(0.14,0.14,0.11));
    this->transform.translate(Vec3(0,-1,-1.5));
    this->rail = 1;
}

Player::~Player(){}

void Player::move_right ( void){
    this->rail += 1;
    this->transform.translate(Vec3(1,0,0));
    this->cam->transform.translate(Vec3(1,0,0));
    this->transform.rotate(Vec3(0,0,-5));
}

void Player::move_left ( void ){
    this->rail -= 1;
    this->transform.translate(Vec3(-1,0,0));
    this->cam->transform.translate(Vec3(-1,0,0));
    this->transform.rotate(Vec3(0,0,5));
}

void Player::jump(void){


    std::cout << "jump" << std::endl;
}

void Player::update(float delta){

}
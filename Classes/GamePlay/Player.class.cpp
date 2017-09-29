#include "Player.class.hpp"

Player::Player(Camera * cam) : GameObject(){
    this->cam = cam;
    this->meshName = "player";
    this->transform.scalate(Vec3(0.14,0.14,0.11));
    this->init_pos = Vec3(0,-1,-1.5);
    this->transform.translate(this->init_pos);
    this->rail = 1;
    this->moving_left = false;
    this->moving_right = false;
    this->lateral_speed = 20.0f;
    this->jumping = false;

}

Player::~Player(){}

void Player::move_right ( void){
    this->rail += 1;
    this->moving_right = true;
    this->transform.rotate(Vec3(0,0,-5));
}

void Player::move_left ( void ){
    this->rail -= 1;
    this->moving_left = true;
    this->transform.rotate(Vec3(0,0,5));
}

void Player::jump(void){
    if (this->jumping)
        return;
    this->jumping = true;
    this->vertical_speed = 7.0f;

    std::cout << "jump" << std::endl;
}

void Player::update(float delta){

    if (this->moving_right){
        this->transform.translate(Vec3(this->lateral_speed * delta,0,0));
        if (this->rail == 2 && this->transform.get_position().x >= 1.0){
            this->moving_right = false;
            this->transform.translate( Vec3(1 - this->transform.get_position().x,0,0));
        }
        else if (this->rail == 1 && this->transform.get_position().x >= 0.0){
            this->moving_right = false;
            this->transform.translate( Vec3(-this->transform.get_position().x,0,0));
        }
    }
    if (this->moving_left){
        this->transform.translate(Vec3(-this->lateral_speed * delta,0,0));
        if (this->rail == 0 && this->transform.get_position().x >= -1.0){
            this->moving_left = false;
            this->transform.translate( Vec3(-1 - this->transform.get_position().x,0,0));
        }
        else if (this->rail == 1 && this->transform.get_position().x <= 0.0){
            this->moving_left = false;
            this->transform.translate( Vec3(-this->transform.get_position().x,0,0));
        }
    }
    if (this->jumping){
        this->transform.translate( Vec3(0, this->vertical_speed * delta ,0));
        this->vertical_speed -= 25 * delta;
        if (this->transform.get_position().y <= this->init_pos.y)
        {
            this->transform.translate( Vec3(0, this->init_pos.y - this->transform.get_position().y  ,0));
            this->jumping = false;
        }
    }

}
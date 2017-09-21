#include "SceneManager.class.hpp"

SceneManager::SceneManager(Player *player){
    this->init_scene(player, false);
}

SceneManager::SceneManager(Player *player, bool isDemo){
    this->init_scene(player, isDemo);
}

void SceneManager::init_scene(Player *player, bool isDemo){
    this->speed = 10;
    srand(time(NULL));
    for(int i = 0; i < NB_ROOM; i++)
    {
        this->rooms[i] = this->new_room(i);
    }
    this->isDemo = isDemo;
    this->player = player;
    // for (GameObject * r : this->rooms)
    // {
    //     std::cout << r->meshName << std::endl;
    // }
}

SceneManager::~SceneManager(void){}

GameObject  *SceneManager::new_room(int index){
    GameObject *room = new GameObject();
    room->meshName = this->roomType[rand() % this->roomType.size()];
    room->transform.position = Vec3(0,-1, -15.5 * index - 9.5);
    return room;
}

void SceneManager::update(double delta){
    for (int i = 0; i < NB_ROOM; i++)
    {
        this->rooms[i]->transform.translate(Vec3(0,0,this->speed * delta));
        if (this->rooms[i]->transform.position.z > 6){
            delete this->rooms[i];
            this->rooms[i] = new_room(NB_ROOM - 1);
        }
    }
}
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

void        SceneManager::add_obstacle(GameObject & room, Mobilier & mob, int index){
    // if (rand() % 100 < 70)
    //     return;
    GameObject *ob = new GameObject();
    ob->meshName = mob.mobilier[rand() % mob.mobilier.size()];
    ob->transform.translate( Vec3(0, 0, index));
    ob->set_parent(&room);
   // this->obstacles.push_back(ob);
}

GameObject  *SceneManager::new_room(int index){
    GameObject *room = new GameObject();
    Mobilier mob = this->roomType[rand() % this->roomType.size()];
    room->meshName = mob.room;
    room->transform.translate(Vec3(0,-1, -15.5 * index - 9.5));

    for (int i = 0; i < 10; i++)
    {
        this->add_obstacle(*room, mob, i);
    }

    return room;
}

void SceneManager::update(double delta){
    for (int i = 0; i < NB_ROOM; i++)
    {
        this->rooms[i]->transform.translate(Vec3(0,0,this->speed * delta));
        if (this->rooms[i]->transform.get_position().z > 6){
            delete this->rooms[i];
            this->rooms[i] = new_room(NB_ROOM - 1);
        }
    }
}

// void SceneManager::update(double delta){
//     this->player->cam->transform.translate(Vec3(0,0,-this->speed * delta));
//     // for (int i = 0; i < NB_ROOM; i++)
//     // {
//     //     this->rooms[i]->transform.translate(Vec3(0,0,this->speed * delta));
//     //     if (this->rooms[i]->transform.get_position().z > 6){
//     //         delete this->rooms[i];
//     //         this->rooms[i] = new_room(NB_ROOM - 1);
//     //     }
//     // }
// }
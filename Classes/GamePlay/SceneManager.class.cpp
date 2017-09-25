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
        if (i == 0)
            this->rooms[i] = this->new_room();
        else
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
    if (rand() % 100 < 70)
        return;
    GameObject *ob = new GameObject();
    ob->meshName = mob.mobilier[rand() % mob.mobilier.size()];
    int ra = rand() % 3;
    ob->transform.translate( Vec3(ra - 1, 0, index));
    ob->transform.scalate(Vec3(0.2,0.2,0.2));
    ob->transform.rotate(Vec3(0,rand() % 360 - 180,0));
    ob->set_parent(&room);
    this->obstacles[ra].push_back(ob);
}

GameObject  *SceneManager::new_room(){
    GameObject *room = new GameObject();
    Mobilier mob = this->roomType[rand() % this->roomType.size()];
    room->meshName = mob.room;
    room->transform.translate(Vec3(0,-1,- 9.5));

    return room;
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

bool SceneManager::check_collision()
{
    std::vector<GameObject *> tab = this->obstacles[this->player->rail];
    for (GameObject * ob : tab)
    {
        Vec4 pOb(ob->transform.get_position(),1.0f);
        pOb = this->player->transform.get_localToWorld() * ob->transform.get_worldToLocal() * pOb;
        float dist = pOb.w != 0.0f ? pOb.z / pOb.w : pOb.z;
        if (dist < 0.3f && dist > 0.0f){
            std::cout << "distance : " << dist << std::endl;
            return (1);
        }
    }

    return (0);
}

void SceneManager::remove_obstacles(std::vector<GameObject *> children){

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < this->obstacles[i].size(); j++)
        {
            for (int k = 0; k < children.size(); k++)
            {
                if (children[k] == this->obstacles[i][j])
                    this->obstacles[i].erase(this->obstacles[i].begin() + j);
            }
        }
    }
}

void SceneManager::update(double delta){
    if (this->pause)
        return;
    if (this->check_collision())
    {
        this->pause = true;
        std::cout << "collide" << std::endl;
    }
    for (int i = 0; i < NB_ROOM; i++)
    {
        this->rooms[i]->transform.translate(Vec3(0,0,this->speed * delta));
        if (this->rooms[i]->transform.get_position().z > 6){
            this->remove_obstacles(this->rooms[i]->_children);
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
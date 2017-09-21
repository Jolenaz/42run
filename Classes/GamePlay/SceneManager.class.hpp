#pragma once
#include "Player.class.hpp"
#include <cstdlib>
#include <ctime>

#define NB_ROOM 10

class SceneManager{

    std::vector<std::string> roomType = {
        "room_cluster"
    };

    public:
    SceneManager(Player *player);
    SceneManager(Player *player, bool isDemo);
    virtual ~SceneManager(void);

    void update(double delta);

    private:
    SceneManager(void);
    SceneManager(SceneManager const &);
    SceneManager & operator=(SceneManager const &);
    void init_scene(Player *player, bool isDemo);

    GameObject  *rooms[NB_ROOM];
    bool        isDemo;
    float       speed;

    GameObject  *new_room(int index);

    Player * player;

};

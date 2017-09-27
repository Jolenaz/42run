#pragma once
#include "Player.class.hpp"
#include <cstdlib>
#include <ctime>

#define NB_ROOM 10

struct Mobilier{
    std::string room;
    std::vector<std::string> mobilier;
};

class SceneManager{

    std::vector<Mobilier> roomType = {
        {"room_cluster", {"chaise_r", "chaise_b" ,"chaise_v", "poubelle"} }
    };


    public:
    SceneManager(Player *player);
    SceneManager(Player *player, bool isDemo);
    virtual ~SceneManager(void);

    void update(double delta);

    bool debug;
    bool pause;

    Player * player;

    private:
    SceneManager(void);
    SceneManager(SceneManager const &);
    SceneManager & operator=(SceneManager const &);
    void init_scene(Player *player, bool isDemo);


    GameObject  *rooms[NB_ROOM];
    bool        isDemo;
    float       speed;

    GameObject  *new_room(int index);
    GameObject  *new_room( void );
    void        add_obstacle(GameObject & room, Mobilier & mob, int index);


    std::vector<GameObject *> obstacles[3];

    bool check_collision(void);

    void remove_obstacles(std::vector<GameObject *> children);


};

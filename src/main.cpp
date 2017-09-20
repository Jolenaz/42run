/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:10:01 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/12 10:10:03 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42run.hpp"
#include <ctime>
// #include "glm/glm.hpp"
// #include "glm/ext.hpp"

int main_loop(RenderManager & rManager, GameObject *rooms)
{
    SDL_Event		ev;
    SDL_PumpEvents();

    rManager.draw();

	if (SDL_PollEvent(&ev))
	{
		if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
			return (0);
{
        // if (ev.key.keysym.sym == SDLK_w){
        //     rManager.cam.translateCam(Vec3(0,0,-1)); 
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_s){
        //     rManager.cam.translateCam(Vec3(0,0,1));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_a){
        //     rManager.cam.translateCam(Vec3(-1,0,0));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_d){
        //     rManager.cam.translateCam(Vec3(1,0,0));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_q){
        //     rManager.cam.translateCam(Vec3(0,-1,0));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_e){
        //     rManager.cam.translateCam(Vec3(0,1,0));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_UP){
        //     rManager.cam.transform.rotate(Vec3(5,0,0));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_DOWN){
        //     rManager.cam.transform.rotate(Vec3(-5,0,0));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_LEFT){
        //     rManager.cam.transform.rotate(Vec3(0,5,0));
        //     rManager.debug = 1;}
        // if (ev.key.keysym.sym == SDLK_RIGHT){
        //     rManager.cam.transform.rotate(Vec3(0,-5,0));
        //     rManager.debug = 1;}
}
        if (ev.key.keysym.sym == SDLK_w)
            rooms->transform.translate(Vec3(0,0,-0.25));
        if (ev.key.keysym.sym == SDLK_s)
            rooms->transform.translate(Vec3(0,0,0.25));
        if (ev.key.keysym.sym == SDLK_a)
            rooms->transform.translate(Vec3(-0.25,0,0));
        if (ev.key.keysym.sym == SDLK_d)
            rooms->transform.translate(Vec3(0.25,0,0));
        if (ev.key.keysym.sym == SDLK_q)
            rooms->transform.translate(Vec3(0,-0.25,0));
        if (ev.key.keysym.sym == SDLK_e)
            rooms->transform.translate(Vec3(0,0.25,0));
        if (ev.key.keysym.sym == SDLK_t)
            std::cout << rooms->transform.position << std::endl;

	}
    return (1);
}

int main()
{

    std::vector<GameObject> rooms;
    RenderManager rManager(1024, 768);

    GameObject roomI;
    roomI.meshName = "room_cluster";
    roomI.transform.position = Vec3(0,-1,-9.5);

    clock_t oldTime = clock();
    int tic;
    float delta;
    float timeru = 0;

    while(main_loop(rManager, &roomI))
    {
        tic = clock() - oldTime;
        oldTime += tic;

        delta = (float)tic / 10000;
        timeru += delta;
        rManager.showFPS(1/delta, false);
        if (timeru >= 0.5)
        {
            timeru = 0;
            rManager.showFPS(1/delta, true);
        }

    }

    return (0);
}

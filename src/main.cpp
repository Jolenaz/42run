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
// #include "glm/glm.hpp"
// #include "glm/ext.hpp"

int main_loop(RenderManager & rManager)
{
    SDL_Event		ev;
    SDL_PumpEvents();

    rManager.draw();

	if (SDL_PollEvent(&ev))
	{
		if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
			return (0);
        if (ev.key.keysym.sym == SDLK_w){
            rManager.cam.transform.translate(Vec3(0,0,-1)); 
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_s){
            rManager.cam.transform.translate(Vec3(0,0,1));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_a){
            rManager.cam.transform.translate(Vec3(-1,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_d){
            rManager.cam.transform.translate(Vec3(1,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_q){
            rManager.cam.transform.translate(Vec3(0,-1,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_e){
            rManager.cam.transform.translate(Vec3(0,1,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_UP){
            rManager.cam.transform.rotate(Vec3(5,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_DOWN){
            rManager.cam.transform.rotate(Vec3(-5,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_LEFT){
            rManager.cam.transform.rotate(Vec3(0,5,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_RIGHT){
            rManager.cam.transform.rotate(Vec3(0,-5,0));
            rManager.debug = 1;}

	}
    return (1);
}

int main()
{

    GameObject rooms[4];
    rooms[0].meshName = "test";
    rooms[0].transform.position = Vec3(5,5,10);
    rooms[1].meshName = "test";
    rooms[1].transform.position = Vec3(-5,-4,-10);
    rooms[2].meshName = "test";
    rooms[3].meshName = "screen";
    rooms[3].transform.position = Vec3(-6,0,0);
    rooms[3].transform.parent = &rooms[0].transform;
    RenderManager rManager(1024, 768);

    while(main_loop(rManager))
    {
        rooms[0].transform.rotation += Vec3(0,1,0);
        rooms[3].transform.rotation += Vec3(1,0,0);
    }

    return (0);
}

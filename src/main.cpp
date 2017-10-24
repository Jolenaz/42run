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

int main_loop(RenderManager & rManager, GameObject *rooms)
{
    SDL_Event		ev;
    SDL_PumpEvents();



	if (SDL_PollEvent(&ev))
	{
		if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
			return (0);

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
            std::cout << rooms->transform.get_position() << std::endl;

	}
    return (1);
}

int main_loop(RenderManager & rManager)
{
    SDL_Event		ev;
    SDL_PumpEvents();

	if (SDL_PollEvent(&ev))
	{
		if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
			return (0);
        if (ev.key.keysym.sym == SDLK_w){
            rManager.cam.translateCam(Vec3(0,0,-1)); 
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_s){
            rManager.cam.translateCam(Vec3(0,0,1));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_a){
            rManager.cam.translateCam(Vec3(-1,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_d){
            rManager.cam.translateCam(Vec3(1,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_q){
            rManager.cam.translateCam(Vec3(0,-1,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_e){
            rManager.cam.translateCam(Vec3(0,1,0));
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
        if (ev.key.keysym.sym == SDLK_t){
            std::cout << rManager.cam.transform.get_position() << std::endl;
        }

	}
    return (1);
}

int main_loop(SceneManager & sManager, RenderManager & rManager)
{
    SDL_Event		ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
			return (0);
        if (sManager.pause)
            return (1);
        if (ev.key.keysym.sym == SDLK_LEFT && ev.key.repeat == 0 && ev.key.type == SDL_KEYDOWN){
            sManager.player->move_left();
            sManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_LEFT && ev.key.repeat == 0 && ev.key.type == SDL_KEYUP){
            sManager.player->move_right();
            sManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_RIGHT && ev.key.repeat == 0 && ev.key.type == SDL_KEYDOWN){
            sManager.player->move_right();
            sManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_RIGHT && ev.key.repeat == 0 && ev.key.type == SDL_KEYUP){
            sManager.player->move_left();
            sManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_UP && ev.key.repeat == 0 && ev.key.type == SDL_KEYDOWN){
            sManager.player->jump();
            sManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_t ){
            rManager.debug = 1;
        }

	}
    return (1);
}

int main()
{
    RenderManager   rManager(1024, 768);
    Player          player(&rManager.cam);
    SceneManager    sManager(&player);

    int     i = 0;
    int     old_time;
    int     tmp;
    double  delta;
    double   timeru = 0;
    sManager.pause = false;

    while(main_loop(sManager, rManager))
    {
        tmp = SDL_GetTicks() - old_time;
        delta = (double)tmp / 1000.0;
        old_time += tmp;
        timeru += delta;
        rManager.showFPS(1/delta, i);
        rManager.draw();
        sManager.update(delta);
        rManager.score = sManager.score;
        player.update(delta);
        i = i < 29 ? i + 1 : 0;
    }

    return (0);
}

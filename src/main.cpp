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
    nk_input_begin(rManager.nkContext);
    //SDL_PumpEvents();

	while (SDL_PollEvent(&ev))
	{
		if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
			return (0);
        if (sManager.pause)
            return (1);
        if (ev.key.keysym.sym == SDLK_LEFT&& ev.key.repeat == 0 && ev.key.type == SDL_KEYDOWN){
            sManager.player->move_left();
            sManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_RIGHT&& ev.key.repeat == 0 && ev.key.type == SDL_KEYDOWN){
            sManager.player->move_right();
            sManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_t ){
            std::cout << sManager.player->cam->transform.get_position() << std::endl;
        }

	}
    nk_input_end(rManager.nkContext);




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

    if (nk_begin(rManager.nkContext, "Demo", nk_rect(50, 50, 200, 200),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
        NK_WINDOW_CLOSABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        nk_menubar_begin(rManager.nkContext);
        nk_layout_row_begin(rManager.nkContext, NK_STATIC, 25, 2);
        nk_layout_row_push(rManager.nkContext, 45);
        if (nk_menu_begin_label(rManager.nkContext, "FILE", NK_TEXT_LEFT, nk_vec2(120, 200))) {
            nk_layout_row_dynamic(rManager.nkContext, 30, 1);
            nk_menu_item_label(rManager.nkContext, "OPEN", NK_TEXT_LEFT);
            nk_menu_item_label(rManager.nkContext, "CLOSE", NK_TEXT_LEFT);
            nk_menu_end(rManager.nkContext);
        }
        nk_layout_row_push(rManager.nkContext, 45);
        if (nk_menu_begin_label(rManager.nkContext, "EDIT", NK_TEXT_LEFT, nk_vec2(120, 200))) {
            nk_layout_row_dynamic(rManager.nkContext, 30, 1);
            
            nk_menu_item_label(rManager.nkContext, "COPY", NK_TEXT_LEFT);
            nk_menu_item_label(rManager.nkContext, "CUT", NK_TEXT_LEFT);
            nk_menu_item_label(rManager.nkContext, "PASTE", NK_TEXT_LEFT);
            nk_menu_end(rManager.nkContext);
        }
        nk_layout_row_end(rManager.nkContext);
        nk_menubar_end(rManager.nkContext);

        enum {EASY, HARD};
        static int op = EASY;
        static int property = 20;
        nk_layout_row_static(rManager.nkContext, 30, 80, 1);
        if (nk_button_label(rManager.nkContext, "button"))
            fprintf(stdout, "button pressed\n");
        nk_layout_row_dynamic(rManager.nkContext, 30, 2);
        if (nk_option_label(rManager.nkContext, "easy", op == EASY)) op = EASY;
        if (nk_option_label(rManager.nkContext, "hard", op == HARD)) op = HARD;
        nk_layout_row_dynamic(rManager.nkContext, 25, 1);
        nk_property_int(rManager.nkContext, "Compression:", 0, &property, 100, 10, 1);
    }
    nk_end(rManager.nkContext);

        tmp = SDL_GetTicks() - old_time;
        delta = (double)tmp / 1000.0;
        old_time += tmp;
        timeru += delta;
        rManager.showFPS(1/delta, i);
        rManager.draw();
        sManager.update(delta);
        i = i < 29 ? i + 1 : 0;
    }

    return (0);
}

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
#include "glm/glm.hpp"
#include "glm/ext.hpp"

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
            rManager.cam.transform.translate(Vec3(0,0,1)); 
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_s){
            rManager.cam.transform.translate(Vec3(0,0,-1));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_a){
            rManager.cam.transform.translate(Vec3(1,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_d){
            rManager.cam.transform.translate(Vec3(-1,0,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_q){
            rManager.cam.transform.translate(Vec3(0,1,0));
            rManager.debug = 1;}
        if (ev.key.keysym.sym == SDLK_e){
            rManager.cam.transform.translate(Vec3(0,-1,0));
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

void print_glm_mat4(glm::mat4x4 mat)
{
    std::cout << "glm :" << std::endl;
      for (int i = 0; i <4; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < 4 ; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }  
    std::cout << std::endl;
}

int main()
{

    GameObject rooms[3];
    rooms[0].meshName = "cube";
    rooms[0].transform.position = Vec3(5,5,10);
    rooms[1].meshName = "cube";
    rooms[1].transform.position = Vec3(-5,-4,-10);
    rooms[2].meshName = "cube";
    RenderManager rManager(1024, 768);

    while(main_loop(rManager))
    {
        
    }


    // Mat4 mat;

    // mat.set_identity();

   
    // // mat.rotateAround(Vec3(1,0,0), 10.0f).rotateAround(Vec3(0,1,0), 23.0f).rotateAround(Vec3(0,0,1), 32.0f);
    // // mat.rotateAround(Vec3(1,0,0), 10.0f).rotateAround(Vec3(0,1,0), 23.0f).rotateAround(Vec3(0,0,1), 32.0f);
    // mat.rotateAround(Vec3(0,1,0), 23.0f).rotateAround(Vec3(1,0,0), 10.0f);

    // std::cout <<"jojo : " << std::endl << mat.transpos() << std::endl;


    // glm::mat4x4 gm(1);

    // gm = gm * glm::rotate((float)(10.0f * M_PI / 180.0f), glm::vec3(1,0,0));

    // gm = gm * glm::rotate((float)(23.0f * M_PI / 180.0f), glm::vec3(0,1,0));
    // // gm = gm * glm::rotate((float)(32.0f * M_PI / 180.0f), glm::vec3(0,0,1));
    // print_glm_mat4(gm);


    return (0);
}

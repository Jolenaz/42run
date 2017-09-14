/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderManager.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:11:08 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:11:11 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector> 
#include <string>
#include <fstream>
#include "render.hpp"
#include "GameObject.class.hpp"
#include <SDL.h>
#include <OpenGL/gl3.h> 

class GameObject;

class RenderManager{

    typedef struct shader_info{
        GLenum	flag;
        std::string addr;
    }   t_shader_info;

    std::vector<std::string> meshNames = 
    {
        "cube", "piece"
    };

    std::vector<t_shader_info> shaders = {
		{ GL_VERTEX_SHADER, "Shaders/general.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/general.frag" }
	};

    public:

    // Constructeurs, Destructeur

    RenderManager(int width, int height);
    virtual ~RenderManager(void);

    // attribus membres

    Camera cam;

    void draw( void );

    private:

    // attribus nom membres

    static std::vector<GameObject*> gameObjects;
    std::vector<Mesh> meshes; 

    //SDL & OpenGL

    void _initSDL(int width, int height);
    SDL_Window      *window;
    SDL_GLContext   glContext;
    int             glProgramId;
    void _loadShader( void );

    // fonctions membres

    RenderManager(void);
    RenderManager(RenderManager const & src);
    RenderManager & operator=(RenderManager const & src);

    // fonctions non membres

    public:

    static void addObject(GameObject *);
    static void removeObject(GameObject *);

};

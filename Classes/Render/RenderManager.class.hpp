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
#include "GameObject.class.hpp"
#include "ObjParser.class.hpp"
#include "Camera.class.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include <OpenGL/gl3.h>

class GameObject;

class RenderManager{

    typedef struct shader_info{
        GLenum	flag;
        std::string addr;
    }   t_shader_info;

    std::vector<std::string> meshNames = 
    {
        "player",
        "e1",
        "e2",
        "tm",
        "couloir",
        "screen",
        "room_cluster",
        "chaise_v",
        "chaise_b",
        "chaise_r",
        "poubelle"
    };

    std::vector<t_shader_info> shaders = {
		{ GL_VERTEX_SHADER, "Shaders/general.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/general.frag" }
    };
    
    std::vector<t_shader_info> uiShaders = {
		{ GL_VERTEX_SHADER, "Shaders/uiShader.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/uiShader.frag" }
	};

    public:

    // Constructeurs, Destructeur

    RenderManager(int width, int height);
    virtual ~RenderManager(void);

    // attribus membres

    Camera cam;
    ObjParser parser;

    void draw( void );
    void showFPS(float FPS , int frameIndex);

    float score = 0.0f;

    private:

    // attribus nom membres

    static std::vector<GameObject*> gameObjects;
    std::vector<Mesh> meshes;
    Mesh textsMesh;




    //SDL & OpenGL

    void _initSDL(int width, int height);
    SDL_Window      *window;
    SDL_GLContext   glContext;
    int             glProgramId;
    int             glUIProgramId;
    int             _loadShader( std::vector<t_shader_info> shaders );


    // fonctions membres

    RenderManager(void);
    RenderManager(RenderManager const & src);
    RenderManager & operator=(RenderManager const & src);
    std::vector<Vertex> create_letter_pos(int index);

    // fonctions non membres

    public:

    static void addObject(GameObject *);
    static void removeObject(GameObject *);

    int debug;
};

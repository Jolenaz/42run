/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderManager.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:19:34 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:19:38 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RenderManager.class.hpp"

RenderManager::RenderManager(int w, int h){
    this->_initSDL(w, h);
    this->_loadShader();
    cam.ratio = (float)w / (float)h;
    for(std::string meshName : meshNames)
    {
        meshes.push_back( this->parser.parseObj( meshName ) );
    }
    for(int i = 0; i < meshes.size(); i++)
    {
        if (this->meshes[i].vertices.size() > 0)
        {
            this->meshes[i].create_vao();
            this->meshes[i].ready = true;
        }
    }
    this->debug = 0;
}

RenderManager::~RenderManager(void){}
std::vector<GameObject*> RenderManager::gameObjects = {};

void RenderManager::addObject(GameObject * go){
    RenderManager::gameObjects.push_back(go);
}

void RenderManager::removeObject(GameObject * go){
    int i = 0;

    for (GameObject * gameObject : RenderManager::gameObjects)
    {
        if (gameObject == go)
            break;
        i++;
    }
    RenderManager::gameObjects.erase( RenderManager::gameObjects.begin() + i);
}

void RenderManager::_initSDL(int width, int height){
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	} else {
		this->window = SDL_CreateWindow("HumanGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if (this->window == NULL) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			// SDL_ShowCursor(SDL_DISABLE);
			// SDL_WarpMouseInWindow(this->window, width / 2, height / 2);
			// SDL_SetWindowGrab(this->window, SDL_TRUE);
			// SDL_SetRelativeMouseMode(SDL_TRUE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
			this->glContext = SDL_GL_CreateContext(this->window);
			if(this->glContext == NULL) {
				std::cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
			}
			glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
			glDepthFunc(GL_LESS);

		}
	}
}

void RenderManager::_loadShader( void ){
    this->glProgramId = glCreateProgram();
    for( t_shader_info si : this->shaders)
    {
        std::string line;
        std::string source_code;

        std::fstream shaderfd(si.addr);
        int shader_id = glCreateShader(si.flag);
        int compilation_return;
        
        if (shaderfd)
        {
            while (getline(shaderfd, line))
                source_code += line + "\n";
            shaderfd.close();
        }
        else
            std::cout << "shader introuvable : " << si.addr << std::endl;
        const char *source_char = source_code.c_str();
        glShaderSource(shader_id, 1, &source_char, NULL);
        glCompileShader(shader_id);
        glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compilation_return);
        if (compilation_return == 0)
        {
            GLchar buf[10000];
	        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &compilation_return);
	        glGetShaderInfoLog(shader_id, 10000, &compilation_return, buf);
	        std::cout << buf << std::endl;
        }
        glAttachShader(this->glProgramId, shader_id);
    }
    glLinkProgram(this->glProgramId);
}

void RenderManager::draw(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // typedef struct s_color{
    //     float r;
    //     float g;
    //     float b;
    //     float a;
    // }   t_color;

    // typedef struct s_vec3{
    //     float r;
    //     float g;
    //     float b;
    // }   t_vec3;

    // typedef struct s_vertex{
    //     t_vec3 pos;
    //     t_color col;
    // }   t_vertex;




    // t_color rouge = {254.0f/255.0f,0.0f/255.0f,0.0f/255.0f,254.0f/255.0f};
	// t_color orange = {254.0f/255.0f,150.0f/255.0f,0,254.0f/255.0f};
	// t_color bleu = {0.0f/255.0f,10.0f/255.0f,230.0f/255.0f,254.0f/255.0f};
	// t_color vert = {80.0f/255.0f,200.0f/255.0f,40.0f/255.0f,254.0f/255.0f};
	// t_color blanc = {254.0f/255.0f,254.0f/255.0f,254.0f/255.0f,254.0f/255.0f};
	// t_color jaune = {254.0f/255.0f,240.0f/255.0f,0.0f/255.0f,254.0f/255.0f};

	// t_vec3 points[8] = {
	// 	{1,1,1},
	// 	{1,1,-1},
	// 	{1,-1,1},
	// 	{1,-1,-1},
	// 	{-1,1,1},
	// 	{-1,1,-1},
	// 	{-1,-1,1},
	// 	{-1,-1,-1}};

	// t_vertex vertices[36] = {
	// 	{points[2], rouge},
	// 	{points[3], rouge},
	// 	{points[1], rouge},
	// 	{points[1], rouge},
	// 	{points[0], rouge},
	// 	{points[2], rouge},
	// 	{points[5], orange},
	// 	{points[7], orange},
	// 	{points[6], orange},
	// 	{points[6], orange},
	// 	{points[4], orange},
	// 	{points[5], orange},
	// 	{points[3], blanc},
	// 	{points[2], blanc},
	// 	{points[6], blanc},
	// 	{points[6], blanc},
	// 	{points[7], blanc},
	// 	{points[3], blanc},
	// 	{points[4], jaune},
	// 	{points[0], jaune},
	// 	{points[1], jaune},
	// 	{points[1], jaune},
	// 	{points[5], jaune},
	// 	{points[4], jaune},
	// 	{points[2], bleu},
	// 	{points[0], bleu},
	// 	{points[4], bleu},
	// 	{points[4], bleu},
	// 	{points[6], bleu},
	// 	{points[2], bleu},
	// 	{points[5], vert},
	// 	{points[1], vert},
	// 	{points[3], vert},
	// 	{points[3], vert},
	// 	{points[7], vert},
	// 	{points[5], vert},
	// };


    // glUseProgram(this->glProgramId);
    // Mat4 VP =  this->cam.get_projMat() * this->cam.transform.get_worldToLocal();

    // GLuint vbo;
    // GLuint vao;

    // glGenBuffers(1, &vbo);
	// glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(t_vertex), &vertices[0], GL_STATIC_DRAW);

	// glGenVertexArrays(1, &vao);
	// glBindVertexArray(vao);

	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (GLvoid*)(0));
	// glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (GLvoid*)(sizeof(t_vec3)) );

	// glEnableVertexAttribArray(0);
	// glEnableVertexAttribArray(1);

    // glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "VP"), 1, GL_TRUE, (const GLfloat*)&VP.value);
    // if (this->debug == 1)
    // {
    //     this->debug = 0;
    //     std::cout << this->cam.transform.get_worldToLocal() << std::endl;
    // }
    // //     glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "models"), models.size() , GL_FALSE, (const GLfloat*)models.data());
    // glBindVertexArray(vao);
    // glDrawArrays(GL_TRIANGLES, 0, 36);

    // glDisableVertexAttribArray(0);
	// glDisableVertexAttribArray(1);

    glUseProgram(this->glProgramId);
    Mat4 VP =  this->cam.get_projMat() * this->cam.transform.get_worldToLocal();

    for (Mesh mesh : meshes)
    {

        if (mesh.ready == false)
            continue;
        //std::vector<Mat4> models;
        // for (GameObject * go : gameObjects)
        // {
        //     if (go->meshName == mesh.name)
        //         models.push_back(go->transform.get_worldToLocal());
        // }
        glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "VP"), 1, GL_TRUE, (const GLfloat*)&VP.value);
        //glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "models"), models.size() , GL_FALSE, (const GLfloat*)models.data());
        glBindVertexArray(mesh.vao);
        //glDrawArraysInstanced(GL_TRIANGLES, 0, mesh.vertices.size(), models.size());

        if (this->debug)
        {
            this->debug = 0;
            std::cout << mesh.vertices.size() << std::endl;
        }
        glDrawArrays(GL_TRIANGLES, 0, mesh.vertices.size());
    }

    SDL_GL_SwapWindow(this->window);
}

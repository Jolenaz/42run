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
    cam.ratio = (float)w / (float)h;
    for(std::string meshName : meshNames)
    {
        meshes.push_back( this->parser.parseObj( meshName ) );
    }
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

    glUseProgram(this->glProgramId);
    for (Mesh mesh : meshes)
    {
        std::vector<Mat4> models;
        for (GameObject * go : gameObjects)
        {
            if (go->meshName == mesh.name)
                models.push_back(go->transform.get_worldToLocal());
        }
        Mat4 VP = this->cam.get_projMat() * this->cam.transform.get_worldToLocal();

        glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "VP"), 1, GL_FALSE, (const GLfloat*)&VP.value);
        glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "models"), models.size() , GL_FALSE, (const GLfloat*)models.data());
        glBindVertexArray(mesh.vao);
        glDrawArraysInstanced(GL_TRIANGLES, 0, mesh.vertices.size(), models.size());
    }

}

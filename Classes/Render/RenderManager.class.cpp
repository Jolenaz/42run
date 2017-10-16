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
    cam.transform.translate(Vec3(0,0.5,-0.3));
    cam.transform.rotate(Vec3(-20.0,0,0));
    for(std::string meshName : meshNames)
    {
        meshes.push_back( this->parser.parseObj( meshName ) );
    }
    for(int i = 0; i < meshes.size(); i++)
    {
        if (this->meshes[i].vertices.size() > 0)
        {
            this->meshes[i].textureID = this->parser.parseTexture(this->meshes[i].name);
            this->meshes[i].ready = true;
            this->meshes[i].create_vao();
        }
    }
    this->debug = 0;
    glUseProgram(this->glProgramId);
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
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	} else {
		this->window = SDL_CreateWindow("HumanGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if (this->window == NULL) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
			this->glContext = SDL_GL_CreateContext(this->window);
            SDL_GL_SetSwapInterval(0);
			if(this->glContext == NULL) {
				std::cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
			}
			glEnable(GL_DEPTH_TEST);
            glEnable(GL_BLEND);
            // glEnable(GL_CULL_FACE);
            // glCullFace(GL_BACK);
			// glDepthFunc(GL_LESS);
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
    Mat4 VP =  this->cam.get_projMat() * this->cam.transform.get_localToWorld();
    glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "VP"), 1, GL_TRUE, (const GLfloat*)&VP.value);

    glUseProgram(this->glProgramId);
    glEnable(GL_DEPTH_TEST);
    for (int i = 0; i < this->meshes.size(); i++){
        if (this->meshes[i].ready == false)
            continue;

        std::vector<Mat4> models;

        for (int j = 0; j < this->gameObjects.size(); j++){
            if (this->gameObjects[j]->meshName == this->meshes[i].name){
                models.push_back(this->gameObjects[j]->transform.get_worldToLocal());
            }
        }

        if (this->meshes[i].textureID != -1)
	        glBindTexture(GL_TEXTURE_2D, this->meshes[i].textureID);

        glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "models"), models.size(), GL_TRUE, (const GLfloat*)models.data());

        glBindVertexArray(this->meshes[i].vao);
        glDrawArraysInstanced(GL_TRIANGLES, 0, this->meshes[i].vertices.size(), models.size());

    }
    SDL_GL_SwapWindow(this->window);
}

void RenderManager::showFPS(float FPS, int frameIndex ){
    static float mo = 0;

    if (frameIndex < 29)
    {
        mo += FPS;
        return;
    }

    char str[100];
    sprintf(str, "%.1f pour %lu objects", mo/30, this->gameObjects.size());
    SDL_SetWindowTitle(this->window, str);
    mo = 0;

    sprintf(str, "distance : %d ", int(this->score));
    SDL_SetWindowTitle(this->window, str);
}

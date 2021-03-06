/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjParser.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:55:28 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 15:55:31 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjParser.class.hpp"

ObjParser::ObjParser( void ){}
ObjParser::~ObjParser( void ){}
ObjParser::ObjParser( ObjParser const & src){}
ObjParser & ObjParser::operator=( ObjParser const & ){return *this;}

int ObjParser::parseTexture(std::string objName){
    // std::fstream textureFile("./Objects/" + objName + ".bmp");
    // if (!textureFile)
    //     return (-1);
    
	FILE *file = fopen(("./Objects/" + objName + ".bmp").c_str(), "rb");
	if (file == NULL){
        printf ("Error: File does not exist");
        return (-1);
    }

    unsigned int    data_pos;
    unsigned int    width, height;
    unsigned int    image_size;
    unsigned int    image_id;
    unsigned char	header[138];
    char            *data;

    fread(header, 1, 138, file);
	data_pos = *(int*)&(header[0x0A]);
	width = *(int*)&(header[0x12]);
    height = *(int*)&(header[0x16]);
    if (objName == "text")
        image_size = width * height * 4;
    else
        image_size = width * height * 3;
    rewind(file);
    fread(header, 1, data_pos, file);
	data = (char*)malloc(image_size * sizeof(char));
	fread(data, 1, image_size, file);
	fclose(file);
	glGenTextures(1, &(image_id));
	glBindTexture(GL_TEXTURE_2D, image_id);
    if (objName == "text")
	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    else
	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    free(data);
    return (image_id);
}

Mesh ObjParser::parseObj(std::string objName){
    this->vertexVect.clear();
    this->vertexVect.push_back(Vec3());
    this->normalVect.clear();
    this->normalVect.push_back(Vec3());
    this->texturVect.clear();
    this->texturVect.push_back(Vec2());
    Mesh ret;
    ret.name = objName;
    std::fstream objFile("./Objects/" + objName + ".obj");
    std::string line;
    if (objFile)
    {
        while(getline(objFile, line))
        {

            if (line[0] == '#')
                continue;
            if (line[0] == 'v')
                this->parse_v_line(line);
            if (line[0] == 'f')
            {
                try{
                this->parse_f_line(line, ret);
                } catch (std::exception &e){
                    std::cerr << e.what() << std::endl;
                    exit(EXIT_FAILURE);
                }

            }
        }
    }
    else
        std::cout << "impossible d'ouvrir le fichier : ./Objects/" + objName + ".obj" << std::endl;
    return ret;
}

void ObjParser::parse_v_line(std::string line){
    if (line[1] && line[1] == ' '){
        std::smatch sm;
        Vec3 vertex;
        std::regex e ("^\\s*v\\s+([\\+\\-]*\\d+\\.\\d+)\\s+([\\+\\-]*\\d+\\.\\d+)\\s+([\\+\\-]*\\d+\\.\\d+)\\s*$");
        if (std::regex_match(line, sm, e)){
            vertex.x = atof(sm[1].str().c_str());
            vertex.y = atof(sm[2].str().c_str());
            vertex.z = atof(sm[3].str().c_str());
        }
        this->vertexVect.push_back(vertex);
        return;
    }
    if (line[1] && line[1] == 'n'){
        std::smatch sm;
        Vec3 normal;
        std::regex e ("^\\s*vn\\s+([\\+\\-]*\\d+\\.\\d+)\\s+([\\+\\-]*\\d+\\.\\d+)\\s+([\\+\\-]*\\d+\\.\\d+)\\s*$");
        if (std::regex_match(line, sm, e)){
            normal.x = atof(sm[1].str().c_str());
            normal.y = atof(sm[2].str().c_str());
            normal.z = atof(sm[3].str().c_str());
        }
        this->normalVect.push_back(normal);
        return;
    }
    if (line[1] && line[1] == 't'){
        std::smatch sm;
        Vec2 texture;
        std::regex e ("^\\s*vt\\s+([\\+\\-]*\\d+\\.\\d+)\\s+([\\+\\-]*\\d+\\.\\d+)\\s*\\d*\\.*\\d*$");
        if (std::regex_match(line, sm, e)){
            texture.x = atof(sm[1].str().c_str());
            texture.y = atof(sm[2].str().c_str());
        }
        this->texturVect.push_back(texture);
        return;
    }
}

void ObjParser::parse_f_line(std::string line, Mesh & ret){
    std::regex re ("(\\d+)\\/?(\\d*)\\/?(\\d*)");
    std::sregex_iterator next(line.begin(), line.end(), re);
    std::sregex_iterator end;
    Vertex vert0;
    Vertex verti_1;
    int i = 0;
    while (next != end) {
        i++;
        std::smatch match = *next;
        next++;
        int i1 = atof(match[1].str().c_str());
        int i2 = atof(match[2].str().c_str());
        int i3 = atof(match[3].str().c_str());
        i2 = i2 == -1 ? 0 : i2;
        i3 = i3 == -1 ? 0 : i3;
        if (i1 < 0 || i1 >= this->vertexVect.size() ||
            i2 < 0 || i2 >= this->texturVect.size() ||
            i3 < 0 || i3 >= this->normalVect.size())
        {
            throw std::exception();   
        }
        if (i == 1){
            vert0 = Vertex(
                this->vertexVect[i1],
                this->normalVect[i3],
                this->texturVect[i2]);
        }
        else if (i == 2){
            verti_1 = Vertex(
                this->vertexVect[i1],
                this->normalVect[i3],
                this->texturVect[i2]);
        }
        else{
            ret.vertices.push_back(vert0);
            ret.vertices.push_back(verti_1);
            verti_1 = Vertex(
                this->vertexVect[i1],
                this->normalVect[i3],
                this->texturVect[i2]);
            ret.vertices.push_back(verti_1);
        }
        
    }
}

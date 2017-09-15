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

Mesh ObjParser::parseObj(std::string objName){
    this->vertexVect.clear();
    this->normalVect.clear();
    this->texturVect.clear();
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
                this->parse_f_line(line, ret);
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
    std::regex re ("\\d+\\/\\d*\\/\\d*");
    std::sregex_iterator next(line.begin(), line.end(), re);
    std::sregex_iterator end;
    int i = 0;
    while (next != end) {
        i++;
        std::smatch match = *next;
        std::cout << match.str() + " ";
        next++;
    }
    std::cout << i << " matches "<< std::endl;

}

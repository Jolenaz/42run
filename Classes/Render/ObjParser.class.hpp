/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjParser.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:55:32 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 15:55:38 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <regex>
#include <fstream>
#include "joMath.hpp"
#include "Mesh.class.hpp"
#include "Vertex.class.hpp"

class ObjParser{

    public:
    ObjParser( void );
    virtual ~ObjParser( void );

    private:
    ObjParser( ObjParser const & );
    ObjParser & operator=( ObjParser const & );

    std::vector<Vec3> vertexVect;
    std::vector<Vec3> normalVect;
    std::vector<Vec2> texturVect;

    void parse_v_line(std::string);
    void parse_f_line(std::string, Mesh &);

    public:

    Mesh parseObj(std::string objName);

};

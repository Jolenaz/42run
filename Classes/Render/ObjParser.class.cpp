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
    Mesh ret;

    return ret;
}

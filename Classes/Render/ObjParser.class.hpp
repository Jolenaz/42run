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
#include "render.hpp"

class ObjParser{

    public:
    ObjParser( void );
    virtual ~ObjParser( void );

    private:
    ObjParser( ObjParser const & );
    ObjParser & operator=( ObjParser const & );

    public:

    static Mesh parseObj(std::string objName);

};

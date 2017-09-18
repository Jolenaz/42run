/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:05:16 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 17:05:22 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "struct.hpp"
#include "Vertex.class.hpp"
#include <vector>
#include <SDL.h>
#include <OpenGL/gl3.h> 

class Mesh{

    public:
    Mesh(void);
    virtual ~Mesh(void);
    Mesh(Mesh const &);
    Mesh & operator=(Mesh const &);

    bool ready;

    std::string name;

    std::vector<Vertex> vertices;

    void    create_vao(void);

    GLuint vao;

};

std::ostream & operator<<(std::ostream & o, Mesh const & i);

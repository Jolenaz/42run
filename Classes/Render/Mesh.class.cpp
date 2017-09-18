/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:05:22 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 17:05:26 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mesh.class.hpp"

Mesh::Mesh(void){
    this->ready = false;
    this->name = "default";
    this->vertices.clear();
}
Mesh::~Mesh(void){}
Mesh::Mesh(Mesh const & src){
    this->ready = src.ready;
    this->name = src.name;
    this->vertices = src.vertices;
}
Mesh & Mesh::operator=(Mesh const & rhs){
    this->ready = rhs.ready;
    this->name = rhs.name;
    this->vertices = rhs.vertices;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Mesh const & i){
    o << "mesh : " << i.name << std::endl;
    for(Vertex const & vert : i.vertices)
    {
        o << "| " << vert << " |" << std::endl; 
    }
    return o;
}

void    Mesh::create_vao(void){
	GLuint	vbo; 

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(0));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vec3)) );
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vec3) * 2) );

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}

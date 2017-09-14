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
#include <vector>

class Mesh{

    public:
    Mesh(void);
    virtual ~Mesh(void);
    Mesh(Mesh const &);
    Mesh & operator=(Mesh const &);

    std::string name;

    std::vector<Vertex> vertices;

    int vao;
};

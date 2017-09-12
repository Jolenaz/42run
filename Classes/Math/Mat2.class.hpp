/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat2.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:02:52 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/12 17:03:10 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "joMath.hpp"

class Mat2{

public:

// Constructeurs, Destructeur

    Mat2(void);
    Mat2(Mat2 const & src);
    Mat2(float x, float y);
    virtual ~Mat2(void);
    Mat2 & operator=(Mat2 const & src);


// attribus

    float x;
    float y;

// fonctions membres

    Mat2    operator+(Mat2 const & src) const;
    Mat2    operator-(Mat2 const & src) const;
    Mat2    operator*(Mat2 const & src) const;
    Mat2    operator*(float const & src) const;
    

// fonctions non membres


};

std::ostream & operator<<(std::ostream & o, Mat2 const & i);

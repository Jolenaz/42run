/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:10:01 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/12 10:10:03 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42run.hpp"

int main()
{
    std::cout << "z : " << Vec3::cross(Vec3(1,0,0),Vec3(0,1,0)) << std::endl;
    std::cout << "-y : " << Vec3::cross(Vec3(1,0,0),Vec3(0,0,1)) << std::endl;
    std::cout << "-x : " << Vec3(0,0,1).cross(Vec3(0,1,0)).normalize() << std::endl;
    return (0);
}

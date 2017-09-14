/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:10:16 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:10:19 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Transform.class.hpp"
#include "RenderManager.class.hpp"

class GameObject{

    public:

    // Constructeurs, Destructeur
    GameObject( void );
    GameObject(GameObject * parent);
    GameObject(GameObject const & src);
    virtual ~GameObject( void );
    GameObject & operator=(GameObject const & src);

    Transform transform;

    std::string meshName;

    GameObject * get_parent( void ) const;
    void set_parent(GameObject *);

    void addChild(GameObject *);
    void removeChild(GameObject *);

    private:

    GameObject * _parent;
    std::vector<GameObject *> _children;
    

    // attribus

    // fonctions membres

    // fonctions non membres
};

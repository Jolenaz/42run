/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:18:41 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:18:46 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.class.hpp"

GameObject::GameObject(){
    this->meshName = "cube";
    this->_parent = NULL;
    RenderManager::addObject(this);
}

GameObject::GameObject(GameObject * parent){
    this->meshName = "cube";
    this->set_parent(parent);
    RenderManager::addObject(this);
}

GameObject::GameObject(GameObject const & src){
    this->meshName = src.meshName;
    this->transform = src.transform;
    this->_parent = src.get_parent();
    if (this->_parent != NULL)
        this->_parent->addChild(this);
    RenderManager::addObject(this);
}

GameObject::~GameObject(){
    int j = this->_children.size();
    for (int i = 0; i < j; i++)
    {
        delete this->_children[0];
    }
    RenderManager::removeObject(this);
    if (this->_parent != NULL)
        this->_parent->removeChild(this);
}

GameObject & GameObject::operator=(GameObject const & src){
    this->meshName = src.meshName;
    this->transform = src.transform;
    this->_parent = src.get_parent();
    if (this->_parent != NULL)
        this->_parent->addChild(this);
    return *this;
}

GameObject * GameObject::get_parent() const{
    return (this->_parent);
}

void GameObject::set_parent(GameObject * parent){
    this->transform.parent = &parent->transform;
    this->_parent = parent;
    this->_parent->addChild(this);

}

void GameObject::addChild(GameObject * go){
    this->_children.push_back(go);
}

void GameObject::removeChild(GameObject * go){
    int i = 0;

    for (GameObject * gameObject : this->_children)
    {
        if (gameObject == go)
            break;
        i++;
    }
    this->_children.erase( this->_children.begin() + i);
}
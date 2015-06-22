//
//  Bullet.cpp
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Bullet.h"

Bullet::Bullet()
{
    this->setTexture(this->texture);
}

Bullet::~Bullet()
{
    
}

void Bullet::move(char direction){
    if (direction=='w') {
        this->setPosition(this->getPosition().x,this->getPosition().y-this->getSpeed());
    }else if(direction=='s'){
        this->setPosition(this->getPosition().x,this->getPosition().y+this->getSpeed());
    }else if(direction=='a'){
        this->setPosition(this->getPosition().x-0.5*this->getSpeed(),this->getPosition().y+this->getSpeed());
    }else if(direction=='d'){
        this->setPosition(this->getPosition().x+0.5*this->getSpeed(),this->getPosition().y+this->getSpeed());
    }
}

void Bullet::setSpeed(int speed)
{
    this->speed=speed;
}

int Bullet::getSpeed(){
    return this->speed;
}
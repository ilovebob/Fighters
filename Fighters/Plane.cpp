//
//  Plane.cpp
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Plane.h"
#include "Sky.h"
#include "GTexture.h"

Plane::Plane(Sky* mySky):mySky(mySky)
{

}

Plane::~Plane()
{
    
}

void Plane::fire(){
   /* Bullet *bullet=new Bullet();
    bullet->setPosition(this->getPosition().x+45,this->getPosition().y-30);
    this->mySky->addBullet(bullet,1);*/
}

void Plane::move (char direction)
{
    if(direction=='a'){
        this->setPosition(this->getPosition().x-this->speed,this->getPosition().y);
    }else if(direction=='d'){
        this->setPosition(this->getPosition().x+this->speed,this->getPosition().y);
    }else if(direction=='s'){
        this->setPosition(this->getPosition().x,this->getPosition().y+this->speed);
    }else if(direction=='w'){
        this->setPosition(this->getPosition().x,this->getPosition().y-this->speed);
    }
}

void Plane::setSpeed(int speed)
{
    this->speed=speed;
}

void Plane::setBulletSpeed(int speed){
    this->BulletSpeed=speed;
}
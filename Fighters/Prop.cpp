//
//  Prop.cpp
//  Fighters
//
//  Created by zhutun on 15/6/22.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Prop.h"
#include<math.h>
#include<time.h>
//#include<SFML/Window.hpp>
#include<GTexture.h>
#include<Sky.h>
Prop::Prop(int x, int y){
    this->setPosition(x, y);
    srand(time(NULL));
    int i=abs(rand()%3);
    if(i==0){
        propsTexture=&GTexture::PROP_SHIELD;
    }else if(i==1){
        propsTexture=&GTexture::PROP_LIFE;
    }else if(i==2){
        propsTexture=&GTexture::PROP_ATTACK;
    }
    this->setTexture(*propsTexture);
}

Prop::~Prop(){
    
}

void Prop::move(){
    this->setPosition(this->getPosition().x,this->getPosition().y+this->speed);
}

void Prop::propeffect(Sky *sky){
    if(this->propsTexture==&GTexture::PROP_LIFE){
        sky->myplane->life++;
    }else if(this->propsTexture==&GTexture::PROP_ATTACK){
        sky->myplane->attack(5);
    }else if(this->propsTexture==&GTexture::PROP_SHIELD){
        sky->myplane->setshield(true);
    }
}

void Prop::setSpeed(int speed){
    this->speed=speed;
}

int Prop::getSpeed(){
    return this->speed;
}
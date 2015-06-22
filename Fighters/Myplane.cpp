//
//  Myplane.cpp
//  Fighters
//
//  Created by zhutun on 15/5/25.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Myplane.h"
#include "GTexture.h"
#include <SFML/System.hpp>
#include "Bullet.h"

Myplane::Myplane(Sky* mySky):Plane(mySky)
{
    this->setTexture(this->texture);
    this->setPosition(450,1450);
}
Myplane::~Myplane()
{
    
}

void Myplane::fire(){
    static int i=0;
    if(i>this->fireDensity){
        this->FIRE.play();
        Bullet *bulletL=new Bullet();
        Bullet *bulletR=new Bullet();
        bulletL->setSpeed(this->BulletSpeed+upspeed);
        bulletR->setSpeed(this->BulletSpeed+upspeed);
        bulletL->setPosition(this->getPosition().x+10,this->getPosition().y);
        bulletR->setPosition(this->getPosition().x+80,this->getPosition().y);
        this->mySky->addBullet(bulletL,1);
        this->mySky->addBullet(bulletR,1);
        i=0;
    }else{
        i++;
    }
}

void Myplane::attack(int upspeed) {
    this->upspeed=upspeed;
    this->fireDensity-=upspeed;
}

void Myplane::setfireDensity(int de){
    this->fireDensity=de;
    
}

void Myplane::addScore(int score)
{
    this->score+=score;
}

int Myplane::getScore()
{
    return score;
}

void Myplane::clearScore()
{
    this->score=0;
}

int Myplane::getlife(){
    return this->life;
}

void Myplane::addlife(){
    this->life++;
}

bool Myplane::dead(){
    this->BOOM.play();
    life--;
    this->state=1;
    return life==0;
}

void Myplane::myplanestate()
{
    sf::Sprite boomImg;
    switch (this->state) {
        case 0:
            break;
        case 1:
            this->BOOM.play();
            state++;
            // break;
        case 2:
            boomImg.setTexture(GTexture::MYPLANE_BOOM1);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            state++;
            // break;
        case 3:
            boomImg.setTexture(GTexture::MYPLANE_BOOM2);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            state++;
            // break;
        case 4:
            boomImg.setTexture(GTexture::MYPLANE_BOOM3);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            state++;
            // break;
        case 5:
            boomImg.setTexture(GTexture::MYPLANE_BOOM4);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            break;
    }
}

void Myplane::setshield(bool shield){
    this->shield=shield;
}
void Myplane::gameagain(){
    this->score=0;
    this->life=3;
    this->setPosition(450, 1450);
    this->setSpeed(10);
}
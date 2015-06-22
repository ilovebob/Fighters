//
//  Enemy.cpp
//  Fighters
//
//  Created by zhutun on 15/5/26.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Enemy.h"
#include "Sky.h"
#include <iostream>
#include <time.h>
#include <random>
#include "Game.h"
#include <SFML/Audio.hpp>   
using namespace std;

Enemy::Enemy(Sky* mySky):Plane(mySky)
{
    uniform_int_distribution<unsigned> u(0,700);
    uniform_int_distribution<unsigned> y(0,10);
    std::default_random_engine random_engine;
    if (y(Game::random_engine)==0) {
        this->setTexture(this->Bossnormal);
        this->flat=2;
        this->Score=5;
    }else{
        this->setTexture(this->Enemynormal);
        this->flat=1;
        this->Score=1;
    }
    this->setPosition(u(Game::random_engine), 0);
    _time=new int;
    
}

Enemy::~Enemy()
{
    
}

void Enemy::enemystate()
{
    sf::Sprite boomImg;
    switch (this->state) {
        case 0:
            this->move('s');
            break;
        case 1:
            this->BOOM.play();
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM1);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM1);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
        case 2:
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM2);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM2);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
        case 3:
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM3);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM3);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
        case 4:
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM4);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM4);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
            break;
        default:
            break;
    }
}

void Enemy::fire()
{
    if (flat==1) {
        static int i=80;
        if(i>this->fireDensity){
            Bullet *bullet=new Bullet();
            bullet->setSpeed(this->BulletSpeed);
            bullet->setPosition(this->getPosition().x+24,this->getPosition().y+30);
            this->mySky->addBullet(bullet,2);
            i=0;
        }else i++;
    }else if (flat==2){
        static int i=50;
        if(i>this->fireDensity){
            Bullet *bullet1=new Bullet();
            Bullet *bullet2=new Bullet();
            Bullet *bullet3=new Bullet();
            Bullet *bullet4=new Bullet();
            Bullet *bullet5=new Bullet();
            bullet1->setSpeed(1.2*this->BulletSpeed);
            bullet2->setSpeed(1.2*this->BulletSpeed);
            bullet3->setSpeed(1.2*this->BulletSpeed);
            bullet4->setSpeed(1.2*this->BulletSpeed);
            bullet5->setSpeed(1.2*this->BulletSpeed);
            bullet1->setPosition(this->getPosition().x+40,this->getPosition().y+230);
            bullet2->setPosition(this->getPosition().x+60,this->getPosition().y+230);
            bullet3->setPosition(this->getPosition().x+80,this->getPosition().y+230);
            bullet4->setPosition(this->getPosition().x+100,this->getPosition().y+230);
            bullet5->setPosition(this->getPosition().x+120,this->getPosition().y+230);
            this->mySky->addBullet(bullet1,3);
            this->mySky->addBullet(bullet2,3);
            this->mySky->addBullet(bullet3,2);
            this->mySky->addBullet(bullet4,4);
            this->mySky->addBullet(bullet5,4);
            i=0;
        }else i++;
    }
}

int Enemy::getScore(){
    return this->Score;
}

int Enemy::getFlat(){
    return this->flat;
}

void Enemy::setFireDensity(int density){
    this->fireDensity=density;
}
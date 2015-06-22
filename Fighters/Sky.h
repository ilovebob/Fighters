//
//  Sky.h
//  Fighters
//
//  Created by zhutun on 15/6/22.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Sky__
#define __Fighters__Sky__

#include <SFML/Graphics.hpp>
#include"GTexture.h"
#include <iostream>
#include<unordered_set>
#include"Myplane.h"
#include "Bullet.h"
#include "Enemy.h"
#include <Prop.h>

class Myplane;
using namespace std;

class Sky:public sf::Sprite
{
public:
    Sky(sf::RenderWindow *window);
    virtual ~Sky();
    void add (Myplane *myplane);
    void refresh();
    
    sf::RenderWindow *window;
    Myplane *myplane;
    
    void addBullet(Bullet* bullet,int flat);
    void moveBullet();
    void clearBullet();
    
    void setEnemyCreateRate(int rate);
    void createEnemies();
    void setEnemySpeed(int speed);
    void enemyFire();
    
    void clearEnemyAndBullet();
    void setEnemyBulletSpeed(int speed);
    void setEnemyFireDensity(int density);
    
    bool isBeat();
    void gameagain();
    
    void propmoveandget();
protected:
private:
    sf::Texture texture=GTexture::BACKGROUND;
    int createRate=100;
    int enemySpeed=5;
    int enemyBulletSpeed=10;
    int enemyFireDensity=10;
    
    unordered_set<Enemy * > planes;
    unordered_set<Bullet * > myPlanebullets;
    unordered_set<Bullet * > enemybullets;
    unordered_set<Bullet * > bossbulletsl;
    unordered_set<Bullet * > bossbulletsr;
    unordered_set<Prop * > props;
    
};

#endif /* defined(__Fighters__Sky__) */

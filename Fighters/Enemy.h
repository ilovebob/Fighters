//
//  Enemy.h
//  Fighters
//
//  Created by zhutun on 15/5/26.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Enemy__
#define __Fighters__Enemy__

#include <stdio.h>
#include "Plane.h"
#include "GTexture.h"
#include "Music.h"
#include <SFML/Audio.hpp>

class Enemy:public Plane
{
public:
    Enemy(Sky* mySky);
    virtual ~Enemy();
    int state=0;//敌机运行状况 0正常飞行 1～4爆炸过程 5clean
    void enemystate();
    void fire();
    int getScore();
    int getFlat();
    void setFireDensity(int density);
protected:
private:
    sf::Texture Enemynormal=GTexture::ENEMY_NORMAL;
    sf::Texture Bossnormal=GTexture::BOSS_NORMAL;
    sf::Music &BOOM=Music::BOOM;
    int flat;
    int Score;
    int time=1;
    int *_time;
    
};
#endif /* defined(__Fighters__Enemy__) */

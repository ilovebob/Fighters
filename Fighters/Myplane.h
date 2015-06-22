//
//  Myplane.h
//  Fighters
//
//  Created by zhutun on 15/5/25.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Myplane__
#define __Fighters__Myplane__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Music.h"
#include "Plane.h"
#include "Sky.h"

class Sky;
class Myplane :public Plane
{
public:
    Myplane(Sky* mySky);
    virtual ~Myplane();
    
    void fire();
    void attack(int upspeed);
    int upspeed=0;
    void setfireDensity(int);
    
    void addScore(int score);
    int getScore();
    void clearScore();
    
    int life=3;
    int getlife();
    void addlife();
    bool dead();
    
    int state=0;//飞机💥 0正常飞行 1～5飞机爆炸
    void myplanestate();
    
    void setshield(bool shield);
    bool shield=false;
    
    void gameagain();
    

protected:
private:
    int score=0;
    sf::Texture texture=GTexture::MYPLANE_NORMAL;
    sf::Music &FIRE=Music::FIRE;
    sf::Music &BOOM=Music::BOOM;
};
#endif /* defined(__Fighters__Myplane__) */

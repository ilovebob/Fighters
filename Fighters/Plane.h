//
//  Plane.h
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Plane__
#define __Fighters__Plane__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "GTexture.h"
#include "Music.h"

class Sky;
class Plane:public sf::Sprite
{
public:
    Plane(Sky* mySky);
    virtual ~Plane();
    
    virtual void fire();
    void move(char direction);
    void setBulletSpeed(int speed);
    void setSpeed(int speed);

protected:
    Sky* mySky;
    int speed=10;
    int BulletSpeed=20;
    int fireDensity=10;
    sf::Texture texture;
    sf::Music &BOOM=Music::BOOM;
private:
    
};
#endif /* defined(__Fighters__Plane__) */

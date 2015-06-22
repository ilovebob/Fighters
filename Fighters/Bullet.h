//
//  Bullet.h
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Bullet__
#define __Fighters__Bullet__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "GTexture.h"

class Bullet:public sf::Sprite
{
public:
    Bullet();
    virtual ~Bullet();
    void setSpeed(int speed);
    int getSpeed();
    void move(char direction);
protected:
private:
    int speed=20;
    sf::Texture texture=GTexture::BULLET;
};

#endif /* defined(__Fighters__Bullet__) */

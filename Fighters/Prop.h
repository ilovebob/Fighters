//
//  Prop.h
//  Fighters
//
//  Created by zhutun on 15/6/22.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Prop__
#define __Fighters__Prop__

#include<list>
#include<map>
#include <SFML/Graphics.hpp>
//#include <Sky.h>

class Sky;
using namespace std;
class Prop :public sf::Sprite
{
public:
    Prop(int x,int y);
    virtual ~Prop();
    
    void move();
    sf::Texture * propsTexture=NULL;
    int getFlat=0;
    void propeffect(Sky *sky);
    void setSpeed(int speed);
    int getSpeed();
protected:
private:
    int speed=5;
    
};
#endif /* defined(__Fighters__Prop__) */

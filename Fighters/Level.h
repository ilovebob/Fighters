//
//  Level.h
//  Fighters
//
//  Created by zhutun on 15/6/20.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Level__
#define __Fighters__Level__

#include <stdio.h>

typedef struct xLevel
{
    int Score;
    int Life;
    int MyplaneSpeed;
    int MyplaneBulletSpeed;
    int MyplaneFireDensity;
    int enemyCreateRate;
    int enemySpeed;
    int enemyBulletSpeed;
    int enemyFireDensity;
}xLevel;

class Level
{
public:
    Level();
    virtual ~Level();
    const static int sumofLevel=8;
    static xLevel listofLevel[sumofLevel];
    static void load();
};
#endif /* defined(__Fighters__Level__) */

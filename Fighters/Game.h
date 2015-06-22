//
//  Game.h
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Game__
#define __Fighters__Game__

#include <stdio.h>
#include "Sky.h"
#include "Music.h"
#include <random>
#include <ctime>
#include "GTexture.h"
#include "Level.h"

class Game
{
public:
    static std::default_random_engine random_engine;
    Game(Sky* sky);
    virtual ~Game();
    void start();
    void showInfo();
    void gameover(bool win);
    bool nextlevel();
    void gameagain();
    
protected:
private:
    sf::Music &BGM=Music::BGM;
    sf::Text Score;
    int levelofnow=0;
    int lifeofnow;
    int gameoverflat=1;
    bool win=false;
    
    Sky* sky;
};

#endif /* defined(__Fighters__Game__) */

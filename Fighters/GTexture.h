//
//  GTexture.h
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__GTexture__
#define __Fighters__GTexture__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <SFML/Graphics/Font.hpp>

class GTexture
{
public:
    GTexture();
    virtual ~GTexture();
    
    static sf::Texture MYPLANE_NORMAL;
    static sf::Texture MYPLANE_BOOM1;
    static sf::Texture MYPLANE_BOOM2;
    static sf::Texture MYPLANE_BOOM3;
    static sf::Texture MYPLANE_BOOM4;

    static sf::Texture ENEMY_NORMAL;
    static sf::Texture ENEMY_BOOM1;
    static sf::Texture ENEMY_BOOM2;
    static sf::Texture ENEMY_BOOM3;
    static sf::Texture ENEMY_BOOM4;
    
    static sf::Texture BOSS_NORMAL;
    static sf::Texture BOSS_BOOM1;
    static sf::Texture BOSS_BOOM2;
    static sf::Texture BOSS_BOOM3;
    static sf::Texture BOSS_BOOM4;
    static sf::Texture BOSS_BOOM5;
    
    static sf::Texture BULLET;
    
    static sf::Texture BACKGROUND;
    static sf::Texture GAMEOVER;
    static sf::Texture WIN;
    
    static sf::Texture PROP_SHIELD;
    static sf::Texture PROP_LIFE;
    static sf::Texture PROP_ATTACK;
    
    static sf::Font FONT;
    
    static void load();
protected:
private:
};
#endif /* defined(__Fighters__GTexture__) */

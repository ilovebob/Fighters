//
//  GTexture.cpp
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "GTexture.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Main.hpp>
#include <ResourcePath.hpp>

sf::Texture GTexture::MYPLANE_NORMAL;
sf::Texture GTexture::MYPLANE_BOOM1;
sf::Texture GTexture::MYPLANE_BOOM2;
sf::Texture GTexture::MYPLANE_BOOM3;
sf::Texture GTexture::MYPLANE_BOOM4;

sf::Texture GTexture::ENEMY_NORMAL;
sf::Texture GTexture::ENEMY_BOOM1;
sf::Texture GTexture::ENEMY_BOOM2;
sf::Texture GTexture::ENEMY_BOOM3;
sf::Texture GTexture::ENEMY_BOOM4;

sf::Texture GTexture::BOSS_NORMAL;
sf::Texture GTexture::BOSS_BOOM1;
sf::Texture GTexture::BOSS_BOOM2;
sf::Texture GTexture::BOSS_BOOM3;
sf::Texture GTexture::BOSS_BOOM4;
sf::Texture GTexture::BOSS_BOOM5;

sf::Texture GTexture::BULLET;

sf::Texture GTexture::BACKGROUND;
sf::Texture GTexture::GAMEOVER;
sf::Texture GTexture::WIN;

sf::Texture GTexture::PROP_SHIELD;
sf::Texture GTexture::SHIELDPLANE;
sf::Texture GTexture::PROP_LIFE;
sf::Texture GTexture::PROP_ATTACK;

sf::Font GTexture::FONT;

GTexture::GTexture()
{
    
}

GTexture::~GTexture()
{
    
}

void GTexture::load(){
    MYPLANE_NORMAL.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(0,100,144,143));
    MYPLANE_BOOM1.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(165,235,100,125));
    MYPLANE_BOOM2.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(330,495,100,125));
    MYPLANE_BOOM3.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(330,625,100,125));
    MYPLANE_BOOM4.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(445,625,100,125));
    
    ENEMY_NORMAL.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(534, 612, 57, 43));
    ENEMY_BOOM1.loadFromFile(resourcePath()+"shoot.png", sf::IntRect(267, 347, 57, 51));
    ENEMY_BOOM2.loadFromFile(resourcePath()+"shoot.png", sf::IntRect(873, 697, 57, 51));
    ENEMY_BOOM3.loadFromFile(resourcePath()+"shoot.png", sf::IntRect(267, 296, 57, 51));
    ENEMY_BOOM4.loadFromFile(resourcePath()+"shoot.png", sf::IntRect(930, 697, 57, 51));
    
    BOSS_NORMAL.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(335,750,170,255));
    BOSS_BOOM1.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(166,750,170,255));
    BOSS_BOOM2.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(166,750,170,255));
    BOSS_BOOM3.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(0,483,170,255));
    BOSS_BOOM4.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(0,225,170,255));
    BOSS_BOOM5.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(676,750,170,255));
                            
    BULLET.loadFromFile(resourcePath()+"shoot.png",sf::IntRect(68, 80, 9, 21));
    BACKGROUND.loadFromFile(resourcePath()+"background.png");
    GAMEOVER.loadFromFile(resourcePath()+"gameover.png");
    WIN.loadFromFile(resourcePath()+"youwin.png");
    
    PROP_SHIELD.loadFromFile(resourcePath()+"shield.png");
    SHIELDPLANE.loadFromFile(resourcePath()+"shieldplane.png");
    PROP_LIFE.loadFromFile(resourcePath()+"life.png");
    PROP_ATTACK.loadFromFile(resourcePath()+"speed.png");
    
    FONT.loadFromFile(resourcePath()+"sansation.ttf");
}
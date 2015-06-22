//
//  Music.cpp
//  Fighters
//
//  Created by zhutun on 15/5/30.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Music.h"
#include <SFML/Audio.hpp>
#include <ResourcePath.hpp>
#include <SFML/System.hpp>

#define BOOMVOLUM 30
#define FIREVOLUM 20

sf::Music Music::BGM;
sf::Music Music::BOOM;
sf::Music Music::FIRE;

Music::Music()
{
    
}

Music::~Music()
{
    
}

void Music::load()
{
    BGM.openFromFile(resourcePath()+"Bgm.ogg");
    BOOM.openFromFile(resourcePath()+"BOOM.wav");
    FIRE.openFromFile(resourcePath()+"Fire.wav");
    BOOM.setVolume(BOOMVOLUM);
    FIRE.setVolume(FIREVOLUM);
}
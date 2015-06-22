//
//  Music.h
//  Fighters
//
//  Created by zhutun on 15/5/30.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#ifndef __Fighters__Music__
#define __Fighters__Music__

#include <stdio.h>
#include <SFML/Audio.hpp>
class Music
{
public:
    Music();
    virtual ~Music();
    
    static sf::Music BGM;
    static sf::Music BOOM;
    static sf::Music FIRE;
    static void load();
    
protected:
private:
};
#endif /* defined(__Fighters__Music__) */

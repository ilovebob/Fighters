//
//  Level.cpp
//  Fighters
//
//  Created by zhutun on 15/6/20.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Level.h"

xLevel Level::listofLevel[8];

Level::Level(){
    
}

Level::~Level(){
    
}

void Level::load(){
    listofLevel[0]={0,0,10,20,10,20,5,8,100};
    listofLevel[1]={30,1,12,25,9,15,5,8,90};
    listofLevel[2]={60,1,14,27,8,10,7,10,80};
    listofLevel[3]={90,1,16,29,7,9,7,10,70};
    listofLevel[4]={120,1,18,31,6,8,9,13,60};
    listofLevel[5]={150,1,20,33,5,7,9,15,50};
    listofLevel[6]={180,1,22,35,4,6,11,16,40};
    listofLevel[7]={1000,1,24,37,3,5,13,18,30};
}
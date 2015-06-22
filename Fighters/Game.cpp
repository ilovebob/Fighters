//
//  Game.cpp
//  Fighters
//
//  Created by zhutun on 15/5/24.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Game.h"
#include <SFML/Audio.hpp>
#include<string.h>
#include<iostream>
#include "Myplane.h"
#include <SFML/Graphics.hpp>

std::default_random_engine Game::random_engine(time(0));

Game::Game(Sky* sky)
{
    this->sky=sky;
}

Game::~Game()
{
    
}

void Game::start(){
    this->BGM.play();
    while (sky->window->isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
            this->sky->clearEnemyAndBullet();
        }//all clean
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if(this->sky->myplane->getPosition().x>0){
                sky->myplane->move('a');
            }
        }//👈
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if(this->sky->myplane->getPosition().x<this->sky->getTextureRect().width*2.0-100){
                sky->myplane->move('d');
            }
        }//👉
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(this->sky->myplane->getPosition().y>0){
                sky->myplane->move('w');
            }
        }//👆
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(this->sky->myplane->getPosition().y<(this->sky->window->getSize().y-this->sky->myplane->getGlobalBounds().height)){
                sky->myplane->move('s');
            }
        } //👇
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space)){
            this->sky->myplane->fire();
        }//开火
        
        sf::Event event;
        while (sky->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed){
               sky->window->close();
                return ;
            }
        }
        
        if (gameoverflat==0) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
                gameagain();
                continue;
            }//replay
            gameover(win);
            continue;
        }else if(gameoverflat==1){
            if (nextlevel()==false) {
                continue;
            }
            if (sky->isBeat()) {
                sky->myplane->myplanestate();
                if (sky->myplane->dead()) {
                    gameoverflat=0;
                    BGM.stop();
                    sky->myplane->setPosition(450, 1450);
                    sky->clearEnemyAndBullet();
                    sky->window->clear();
                    continue;
                }
                sky->clearEnemyAndBullet();
            }
            sky->createEnemies();
            sky->enemyFire();
            sky->moveBullet();
            sky->clearBullet();
            sky->propmoveandget();
            sky->refresh();
            showInfo();
            sky->window->display();
        }
    }
}

void Game::showInfo()
{
    this->lifeofnow=sky->myplane->getlife();
    char str[80];
    sprintf(str,"Level:%d \nScore:%d \nLife:%d",this->levelofnow,this->sky->myplane->getScore(),this->lifeofnow);
    Score.setFont(GTexture::FONT);
    Score.setString(str);
    Score.setColor(sf::Color::Black);
    Score.setCharacterSize(50);
    Score.setPosition(0, 0);
    this->sky->window->draw(Score);
}

void Game::gameover(bool win){
    if(win){
        sky->setTexture(GTexture::WIN);
    }else{
        sky->setTexture(GTexture::GAMEOVER);
    }
    sky->window->draw(*sky);
    sky->window->display();
}

bool Game::nextlevel(){
    if (levelofnow==Level::sumofLevel) {
        win=true;
        gameoverflat=0;
        BGM.stop();
        sky->myplane->setPosition(450, 1450);
        sky->clearEnemyAndBullet();
        sky->window->clear();
        return false;
    }else{
        if (this->sky->myplane->getScore()>=Level::listofLevel[levelofnow].Score) {
            this->sky->myplane->life+=(Level::listofLevel[levelofnow].Life);
            this->sky->myplane->setSpeed(Level::listofLevel[levelofnow].MyplaneSpeed);
            this->sky->myplane->setBulletSpeed(Level::listofLevel[levelofnow].MyplaneBulletSpeed);
            this->sky->myplane->setfireDensity(Level::listofLevel[levelofnow].MyplaneFireDensity);
            this->sky->setEnemyCreateRate(Level::listofLevel[levelofnow].enemyCreateRate);
            this->sky->setEnemySpeed(Level::listofLevel[levelofnow].enemySpeed);
            this->sky->setEnemyBulletSpeed(Level::listofLevel[levelofnow].enemyBulletSpeed);
            this->sky->setEnemyFireDensity(Level::listofLevel[levelofnow].enemyFireDensity);
            levelofnow++;
            std::cout<<levelofnow;
        }
        return true;
    }
}

void Game::gameagain(){
    gameoverflat=1;
    levelofnow=0;
    sky->myplane->setPosition(450, 1450);
    sky->clearEnemyAndBullet();
    sky->window->clear();
    sky->gameagain();
    BGM.play();
}
//
//  Sky.cpp
//  Fighters
//
//  Created by zhutun on 15/6/22.
//  Copyright (c) 2015年 zhutun. All rights reserved.
//

#include "Sky.h"
Sky::Sky(sf::RenderWindow *window):window(window)
{
    this->setTexture(this->texture);
    this->setScale(1.0*this->window->getSize().x/this->texture.getSize().x,1.0*this->window->getSize().y/this->texture.getSize().y);
}

Sky::~Sky()
{
    
}

void Sky::add(Myplane *myplane){
    this->myplane = myplane;
}

void Sky::refresh(){
    this->window->clear();
    this->window->draw(*this);
    this->window->draw(*(this->myplane));
    
    auto enemy = this->planes.begin();
    while (enemy != (this->planes.end())) {
        auto temp=enemy;
        //敌机击中过程
        if((*enemy)->state>=1&&(*enemy)->state<=4){
            (*enemy)->enemystate();
            break;
        }else if((*enemy)->state==5){
            if ((*enemy)->getFlat()==2) {
                Prop* prop=new Prop((*enemy)->getPosition().x+85,(*enemy)->getPosition().y+125);
                props.insert(prop);
            }
            delete *enemy;
            enemy = (this->planes).erase(enemy);
            break;
        }
        (*enemy)->enemystate();
        for(auto sprite = this->myPlanebullets.begin(); sprite!=(this->myPlanebullets.end());){
            if((*enemy)->getGlobalBounds().intersects((*sprite)->getGlobalBounds())){
                static int a=10;
                if ((*enemy)->getFlat()==1) {
                    (*enemy)->state=1;
                    this->myplane->addScore((*enemy)->getScore());
                }else if ((*enemy)->getFlat()==2) {
                    if (a==0) {
                        (*enemy)->state=1;
                        a=5;
                        this->myplane->addScore((*enemy)->getScore());
                    }else{
                        a--;
                    }
                }
                this->myPlanebullets.erase(sprite);
                break;
            }
            sprite++;
        }
        //敌机越界处理
        if((*enemy)->getPosition().y>1600){
            delete *enemy;
            enemy = (this->planes).erase(enemy);
            break;
        }
        
        this->window->draw(**enemy);
        if(temp==enemy){
            enemy++;
        }
    }
    
    for(auto &sprite : this->myPlanebullets){
        this->window->draw(*sprite);
    }
    for(auto &sprite : this->enemybullets){
        
        this->window->draw(*sprite);
    }
    for(auto &sprite : this->bossbulletsl){
        this->window->draw(*sprite);
    }
    for(auto &sprite : this->bossbulletsr){
        
        this->window->draw(*sprite);
    }
    for(auto &sprite : this->props){
        this->window->draw(*sprite);
    }
}

void Sky::addBullet(Bullet *bullet,int flat){
    if (flat==1) {
        this->myPlanebullets.insert(bullet);
    }else if(flat==2){
        this->enemybullets.insert(bullet);
    }else if(flat==3){
        this->bossbulletsl.insert(bullet);
    }else if(flat==4){
        this->bossbulletsr.insert(bullet);
    }
}

void Sky::moveBullet(){
    for(auto &bullet : this->myPlanebullets){
        bullet->move('w');
    }
    for(auto &bullet: this->enemybullets) {
        bullet->move('s');
    }
    for(auto &bullet: this->bossbulletsl) {
        bullet->move('a');
    }
    for(auto &bullet: this->bossbulletsr) {
        bullet->move('d');
    }
}

void Sky::clearBullet(){
    for(auto bullet = this->myPlanebullets.begin(); bullet!=(this->myPlanebullets.end());){
        if((*bullet)->getPosition().y<0){
            delete *bullet;
            bullet = (this->myPlanebullets).erase(bullet);
        }else{
            bullet++;
        }
    }
}

void Sky::setEnemyCreateRate(int rate){
    this->createRate=rate;
}

void Sky::createEnemies()
{
    static int count=0;
    if(++count>=createRate){
        Enemy* enemy = new Enemy(this);
        enemy->setSpeed(enemySpeed);
        this->planes.insert(enemy);
        count = 0;
    }
}

void Sky::setEnemySpeed(int speed){
    this->enemySpeed=speed;
}

void Sky::enemyFire(){
    for(auto enemy = this->planes.begin(); enemy!=(this->planes.end());){
        (*enemy)->setFireDensity(this->enemyFireDensity);
        (*enemy)->setBulletSpeed(this->enemyBulletSpeed);
        (*enemy)->fire();
        enemy++;
    }
}

void Sky::clearEnemyAndBullet(){
    for(auto &bullet : this->enemybullets){
        delete bullet;
    }
    for(auto &bullet : this->bossbulletsl){
        delete bullet;
    }
    for(auto &bullet : this->bossbulletsr){
        delete bullet;
    }
    for(auto &enemy : this->planes){
        delete enemy;
    }
   
    enemybullets.clear();
    bossbulletsr.clear();
    bossbulletsl.clear();
    planes.clear();
}

void Sky::setEnemyBulletSpeed(int speed){
    this->enemyBulletSpeed=speed;
}

void Sky::setEnemyFireDensity(int density){
    this->enemyFireDensity=density;
}

bool Sky::isBeat(){
    if (this->myplane->shield){
        static int a=0;
        if (a==500) {
            a=0;
            this->myplane->shield=false;
            this->myplane->setTexture(GTexture::MYPLANE_NORMAL);
        }else {
            a++;
        }
        return false;
    }
    for(auto &bullet : this->enemybullets){
        if((bullet)->getGlobalBounds().intersects((this->myplane)->getGlobalBounds())){
            return true;
        }
    }
    for(auto &enemy : this->bossbulletsr){
        if((enemy)->getGlobalBounds().intersects((this->myplane)->getGlobalBounds())){
            return true;
        }
    }
    for(auto &enemy : this->bossbulletsl){
        if((enemy)->getGlobalBounds().intersects((this->myplane)->getGlobalBounds())){
            return true;
        }
    }
    for(auto &enemy : this->planes){
        if((enemy)->getGlobalBounds().intersects((this->myplane)->getGlobalBounds())){
            return true;
        }
    }
    return false;
}

void Sky::gameagain(){
    this->setTexture(this->texture);
    this->setScale(1.0*this->window->getSize().x/this->texture.getSize().x,1.0*this->window->getSize().y/this->texture.getSize().y);
    this->myplane->gameagain();
}

void Sky::propmoveandget(){
    for(auto &prop : this->props){
        prop->move();
    }
    for(auto &prop : this->props){
        if((prop)->getGlobalBounds().intersects((this->myplane)->getGlobalBounds())){
            prop->propeffect(this);
            delete prop;
            this->props.erase(prop);
            break;
        }
    }
}


#**C＋＋飞机大战实验报告**

---
学号：2014060108028
姓名：祝暾
指导老师：俸志刚

##一、实验目的
飞机大战是参照微信火热打飞机游戏的简单版，适合单个用户自娱自乐。

##二、游戏规则
1. 打开程序Fighters开启✈️大战。
2. 进入打飞机的游戏后，你就可以按键盘上的方向键控制你的飞机来左右上下移动开始了，控制飞机让其不撞到其他的飞机上，你不可以碰到小飞机，否则你的飞机生命值将减少一点，生命值为0时游戏就结束。
3. 你可以通过按键盘上的空格键来发射子弹摧毁小飞机而得到积分，而摧毁不同敌机可以获得相应积分。当你的积分积累到一定分值时你会进入下一关卡，每进入下一关就会增加3点生命值。
4. 总共8个关卡，随即会产生BOSS，BOSS的生命值为10点（意味着你要打中10次），BOSS死亡后会随即产生三种道具中的一种（加速射击、防御盾、生命值加一点），每一个关卡都比前一个关卡难，敌机移动速度射击速度都会加快，当然相应的玩家也会加快。
5. 有一些特殊功能。在游戏结束时按下F1可以重新开始游戏；在游戏过程中按下F2可以将所有敌机都摧毁但是并不会得分。

##三、实验环境
mac系统下XCode以及SFML图形库。
附：[SFML图形库配置方案链接](http://www.sfml-dev.org/tutorials/2.3/start-osx.php)

##四、实验过程
###Game类
```C++
class Game
{
public:
    static std::default_random_engine random_engine;
    Game(Sky* sky);
    void start();
    void showInformation();
    void gameover(bool win);
    bool nextlevel();
    void gameagain();
};
```
关键代码
1、键盘输入
```C++
if(gameoverflat==0){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
            gameagain();continue;
    }
 }//replay
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
```
###Sky类
```C++
class Sky:public sf::Sprite
{
public:
    Sky(sf::RenderWindow *window);
    virtual ~Sky();
    void add (Myplane *myplane);
    void refresh();
    
    sf::RenderWindow *window;
    Myplane *myplane;
    
    void addBullet(Bullet* bullet,int flat);
    void moveBullet();
    void clearBullet();
    
    void setEnemyCreateRate(int rate);
    void createEnemies();
    void setEnemySpeed(int speed);
    void enemyFire();
    void setEnemyFireDensity(int density);
   
    void clearEnemyAndBullet();
    void setEnemyBulletSpeed(int speed);

    bool isBeat();
    void gameagain();
    
    void propmoveandget();
};
```
关键代码
1、refresh
```C++
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
```
2、飞机被击中
```C++
bool Sky::isBeat(){
    if (this->myplane->shield){
        static int a=0;
        if (a==500) {
            a=0;
            this->myplane->setTexture(GTexture::MYPLANE_NORMAL);
            this->myplane->shield=false;
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
```
###Plane类
```C++
class Plane:public sf::Sprite
{
public:
    Plane(Sky* mySky);
    virtual void fire();
    void move(char direction);
    void attack(int upspeed);
    int shield=0;
    int upspeed=0;
};
```

关键代码
1、飞机移动代码
```C++
void Plane::move (char direction)
{
    if(direction=='a'){
        this->setPosition(this->getPosition().x-speed,this->getPosition().y);
    }else if(direction=='d'){
        this->setPosition(this->getPosition().x+speed,this->getPosition().y);
    }else if(direction=='s'){
        this->setPosition(this->getPosition().x,this->getPosition().y+speed);
    }else if(direction=='w'){
        this->setPosition(this->getPosition().x,this->getPosition().y-speed);
    }
}
```
###Myplane类
```C++
class Myplane :public Plane
{
public:
    Myplane(Sky* mySky);
    virtual ~Myplane();
    
    void fire();
    void attack(int upspeed);
    int upspeed=0;
    void setfireDensity(int);
    
    void addScore(int score);
    int getScore();
    void clearScore();
    
    int life=3;
    int getlife();
    void addlife();
    bool dead();
    
    int state=0;//飞机💥 0正常飞行 1～5飞机爆炸
    void myplanestate();
    
    void setshield(bool shield);
    bool shield=false;
    
    void gameagain();
};
```
关键代码
1、fire
```C++
void Myplane::fire(){
    static int i=0;
    if(i>this->fireDensity){
        this->playmusic();
        Bullet *bulletL=new Bullet();
        Bullet *bulletR=new Bullet();
        bulletL->setSpeed(this->fireSpeed+upspeed);
        bulletR->setSpeed(this->fireSpeed+upspeed);
        bulletL->setPosition(this->getPosition().x+10,this->getPosition().y);
        bulletR->setPosition(this->getPosition().x+80,this->getPosition().y);
        this->mySky->addBullet(bulletL,1);
        this->mySky->addBullet(bulletR,1);
        i=0;
    }else{
        i++;
    }
}
```
2、状态判断
```C++
void Myplane::myplanestate()
{
    sf::Sprite boomImg;
    switch (this->state) {
        case 0:
            break;
        case 1:
            this->BOOM.play();
            state++;
            // break;
        case 2:
            boomImg.setTexture(GTexture::MYPLANE_DEAD);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            state++;
            // break;
        case 3:
            boomImg.setTexture(GTexture::MYPLANE_DEAD1);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            state++;
            // break;
        case 4:
            boomImg.setTexture(GTexture::MYPLANE_DEAD2);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            state++;
            // break;
        case 5:
            boomImg.setTexture(GTexture::MYPLANE_DEAD1);
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            //this->mySky->window->clear();
            this->mySky->window->draw(boomImg);
            this->mySky->window->display();
            state++;
            break;
    }
}
```
###Enemy类
```C++
class Enemy:public Plane
{
public:
    Enemy(Sky* mySky);
    virtual ~Enemy();
    int state=0;//敌机运行状况 0正常飞行 1～4爆炸过程 5clean
    void enemystate();
    void fire();
    int getScore();
    int getFlat();
    void setFireDensity(int density);
};
```
关键代码
1、构造函数
```C++
Enemy::Enemy(Sky* mySky):Plane(mySky)
{
    uniform_int_distribution<unsigned> u(0,700);
    uniform_int_distribution<unsigned> y(0,10);
    std::default_random_engine random_engine;
    if (y(Game::random_engine)==0) {
        this->setTexture(this->Bossnormal);
        this->flat=2;
        this->Score=5;
    }else{
        this->setTexture(this->Enemynormal);
        this->flat=1;
        this->Score=1;
    }
    this->setPosition(u(Game::random_engine), 0);
    _time=new int;
    
}
```
2、fire
```C++
void Enemy::fire()
{
    if (flat==1) {
        static int i=80;
        if(i>this->fireDensity){
            Bullet *bullet=new Bullet();
            bullet->setSpeed(this->fireSpeed);
            bullet->setPosition(this->getPosition().x+24,this->getPosition().y+30);
            this->mySky->addBullet(bullet,2);
            i=0;
        }else i++;
    }else if (flat==2){
        static int i=50;
        if(i>this->fireDensity){
            Bullet *bullet1=new Bullet();
            Bullet *bullet2=new Bullet();
            Bullet *bullet3=new Bullet();
            Bullet *bullet4=new Bullet();
            Bullet *bullet5=new Bullet();
            bullet1->setSpeed(1.5*this->fireSpeed);
            bullet2->setSpeed(1.5*this->fireSpeed);
            bullet3->setSpeed(1.5*this->fireSpeed);
            bullet4->setSpeed(1.5*this->fireSpeed);
            bullet5->setSpeed(1.5*this->fireSpeed);
            bullet1->setPosition(this->getPosition().x+40,this->getPosition().y+230);
            bullet2->setPosition(this->getPosition().x+60,this->getPosition().y+230);
            bullet3->setPosition(this->getPosition().x+80,this->getPosition().y+230);
            bullet4->setPosition(this->getPosition().x+100,this->getPosition().y+230);
            bullet5->setPosition(this->getPosition().x+120,this->getPosition().y+230);
            this->mySky->addBullet(bullet1,3);
            this->mySky->addBullet(bullet2,3);
            this->mySky->addBullet(bullet3,2);
            this->mySky->addBullet(bullet4,4);
            this->mySky->addBullet(bullet5,4);
            i=0;
        }else i++;
    }
}
```
3、状态判断
```C++
void Enemy::enemystate()
{
    sf::Sprite boomImg;
    switch (this->state) {
        case 0:
            this->move('s');
            break;
        case 1:
            this->BOOM.play();
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM1);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM1);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
        case 2:
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM2);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM2);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
        case 3:
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM3);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM3);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
        case 4:
            if (flat==1) {
                boomImg.setTexture(GTexture::ENEMY_BOOM4);
            }else if(flat==2){
                boomImg.setTexture(GTexture::BOSS_BOOM4);
            }
            boomImg.setPosition(this->getPosition().x, this->getPosition().y);
            this->mySky->window->draw(boomImg);
            state++;
            break;
        default:
            break;
    }
}
```
###Prop类
```C++
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
};
```
关键代码
1、道具效果
```C++
void Prop::propeffect(Sky *sky){
    if(this->propsTexture==&GTexture::PROP_LIFE){
        sky->myplane->life++;
    }else if(this->propsTexture==&GTexture::PROP_ATTACK){
        sky->myplane->attack(5);
    }else if(this->propsTexture==&GTexture::PROP_SHIELD){
        sky->myplane->setshield(true);
        sky->myplane->setTexture(GTexture::SHIELDPLANE);
    }
}
```
###UML图
![UML][1]
程序UML图简介
##五、实验效果
###整体效果与游戏截图
整体效果不错，程序不会卡顿，较为流畅。
![Game截图][2]
###程序大小
加上资源一共9MB
###用户体验
用户体验：
	难度阶梯合理，但增长难度的方式较为单一（增加敌机数量、加快敌机速度）。
	当大量敌机被摧毁时，音效噪杂，且没有duang~的特效。
	小兵与boos之间差距过大，后期基本靠打boos获取各种道具维持生命以及攻击力。
	暾暾么么哒(* ‾3)(ε‾ *)~


  [1]: https://raw.githubusercontent.com/ilovebob/Fighters/master/Fighters%20UML.png
  [2]: https://raw.githubusercontent.com/ilovebob/Fighters/master/%E6%B8%B8%E6%88%8F%E6%88%AA%E5%9B%BE.png
// NESTED CLASS

#include<iostream>
using namespace std;

class Gun{
  public:
  int ammo;
  int damage;
  int scope;
};

class player{
private:
int  age;
int health;
int score;
bool alive;
Gun gun;



public:
void sethealth (int health){
    this->health = health;
}
int gethealth(){
    return health;
}
void setage(int age){
    this->age = age;
}
int getage(){
    return age;
}
void setscore(int score){
    this->score = score;
}
int getscore(){
    return score;
}
void setalive(bool alive){
    this-> alive = alive;
} 
bool getalive(){
    return alive;
}

void setGun(Gun gun){
    this->gun = gun;
}

Gun getGun(){
    return gun;
}

};



 int main(){
    Gun akm;
    akm.ammo(47);
    akm.damage(60);
    akm.scope(2);

    player aman;
    aman.setscore(80);
    aman.sethealth(90);
    aman.setage(22);
    aman.setalive(1);
    aman.setGun(akm);

 
   
   Gun awm;
   awm.ammo(10);
   awm.damage(120);
   awm.scope(8);


    player raja;
    raja.sethealth(70);
    raja.setscore(100);
    raja.setage(25);
    raja.setalive(1);
    raja.setGun(awm);

  

    
 }
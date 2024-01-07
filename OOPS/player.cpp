#include<iostream>
using namespace std;
class player{
private:
int age;
int health;
int score;
bool alive;

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
};

void addhealth(player a, player b){
    cout<<a.gethealth() + b.gethealth();
}

player getMaxScore(player a, player b){
    if(a.getscore() > b.getscore())
    return a;
    else 
    return b;
}


 int main(){
    player aman;
    aman.setscore(80);
    aman.sethealth(90);
    aman.setage(22);
    aman.setalive(1);
    // cout<<aman.gethealth;

    player raja;
    raja.sethealth(70);
    raja.setscore(100);
    raja.setage(25);
    raja.setalive(1);

    // addhealth(aman,raja);

    player ravi = getMaxScore(aman,raja);
    cout<<ravi.getscore()<<endl;
    cout<<ravi.gethealth()<<endl;
    
 }
 
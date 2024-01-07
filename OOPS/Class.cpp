#include<iostream>
using namespace std;
class Pokemon{
public:
    string type;
    int attack;
    Pokemon(string type,int attack){
        this->type = type;
        this->attack = attack;
    }
};
int main(){
    Pokemon pikachu("electric",50);
    cout<<pikachu.type<<" "<<pikachu.attack<<endl;
    Pokemon charizard("fire",50);
    cout<<charizard.type<<" "<<pikachu.attack<<endl;
}
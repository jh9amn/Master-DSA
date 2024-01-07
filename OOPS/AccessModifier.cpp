#include<iostream>
using namespace std;
class Pokemon{
private:
    string type;
    int attack;
    public:

    void set(string type){
        this->type = type;
    }
    
    string get(){
        return type;
    }
   
};
int main(){
    Pokemon pikachu;
    pikachu.set("Electric");
    cout<<pikachu.get();

    
    
}
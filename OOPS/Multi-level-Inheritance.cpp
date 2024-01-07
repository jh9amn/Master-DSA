#include<iostream>
using namespace std;
class parent{
    public:
    parent(){
        cout<<"Parent Class is Called"<<endl;
    }
};

class child : public parent{
    public:
    child(){
        cout<<"Child Class is class"<<endl;
    }
};

class grandChild : public child {
    public:
    grandChild (){
        cout<<"grandChild is called"<<endl;
    } 
};
int main(){
  grandChild g;
}
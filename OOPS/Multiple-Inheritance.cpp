#include<iostream>
using namespace std;
class parent1{
    public:
    parent1(){
        cout<<"Parent1 Class is Called"<<endl;
    }
};

class parent2 {
    public:
    parent2(){
        cout<<"parent2 Class is class"<<endl;
    }
};

class  child : public parent1 ,public parent2{
    public:
    child (){
        cout<<"child is called"<<endl;
    } 
};
int main(){
  child c;
}
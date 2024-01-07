#include<iostream>
using namespace std;
class student {

    private:

    int roll;
    int marks;
    string name;

    public:

    void setRoll(int roll){
        this->roll = roll;
    }
    int getRoll(){
        return roll;
    }

    void setMarks(int marks){
        this->marks = marks;
    }
    int getMarks(){
        return marks;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }

};

 int main(){
    
    // Dynamic Memory Allocation

    student *aman = new student;
    // If using * oprator then Do like This otherwise Like Another One using arrow Operator
    (*aman).setName("Hello Aj");
    aman->setName("Hello Aj");
    cout<<aman->getName()<<endl;
    aman->setMarks(80);
    cout<<aman->getMarks()<<endl;
 }
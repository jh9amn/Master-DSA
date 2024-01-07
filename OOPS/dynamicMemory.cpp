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

    // RUN TIME MEMORY ALLOCATION / DYNAMIC MEMORY ALLOCATION
    
    student *aman = new student;
    student amanObject =  *aman;

    amanObject.setName("Hello Buddy");
    amanObject.setRoll(20);
    amanObject.setMarks(80);

    cout<<amanObject.getName()<<endl;
    cout<<amanObject.getRoll()<<endl;
    cout<<amanObject.getMarks()<<endl;
}
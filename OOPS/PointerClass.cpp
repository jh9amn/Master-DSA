#include<iostream>
using namespace std;
class Student{
  public:
    int rno;
    string name;
    float marks;

    Student(int rno,string name,float marks){
        (*this). rno = rno;                // (*abc).x = abc->x
        this -> name = name;
        this -> marks = marks;
    }
};

// Here This is Work as Call By Value ....
// void change(Student s){

// Here This is Work as Call By Address ....
void change(Student& s){
    s.name = "Harsh";
}

 int main(){
    Student s(12,"Aman",84.90);
    Student* ptr = &s;          // Assingnint the address of object s to the Student Type pointer     
    cout<<(*ptr).name<<endl;    // accessing the value usint the pointer
    (*ptr).marks = 90.00;       // changing the Student Object marks value using the pointer
    cout<<(*ptr).marks<<endl;   // printing using Pointer
     ptr->marks = 100.00;       // <<-- we can write this (*ptr).marks = 100.00 as
    cout<<s.marks<<endl;        // print the change value        

 }
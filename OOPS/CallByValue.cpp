#include<iostream>
using namespace std;
class Student{
  public:
    int rno;
    string name;
    float marks;

    Student(int rno,string name,float marks){
        this -> rno = rno;
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
    cout<<s.name<<endl;
    change(s);
    cout<<s.name<<endl;

 }
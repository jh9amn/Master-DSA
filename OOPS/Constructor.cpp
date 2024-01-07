#include<iostream>
using namespace std;
class Student{
public: 
    string name;
    int roll;
    float percent;

    Student(string n,int r,float p){
        name = n;
        roll = r;
        percent = p;
    }
      Student(int r,string n,float p){
        name = n;
        roll = r;
        percent = p;
    }

};
int main(){
    // Student s {"Aman",76,78.88};
    // cout<<s.name<<" "<<s.roll<<" "<<s.percent<<endl;
    // s.name = "Harsh";
    // cout<<s.name<<" "<<s.roll<<" "<<s.percent<<endl;


    //   Student s {"Aman",76,78.88};
    //  cout<<s.name<<" "<<s.roll<<" "<<s.percent<<endl;
     Student s {78,"Aman",78.88};
     cout<<s.name<<" "<<s.roll<<" "<<s.percent<<endl;
}
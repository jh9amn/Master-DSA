#include<iostream>
using namespace std;
class student{
public:
    int roll;
    string name;
    float percent;

}; 
int main(){
    
    // student s;
    // s.name = "Aman";
    // s.percent = 79.9;
    // s.roll = 14;

    student s = {12,"Aman",14.2};
    cout<<s.name<<endl;

    // student y;
    // y.name = "Niraj";
    // y.percent = 76.7;
    // y.roll = 67;

    // student z = s;
    // z.name = "Harsh";
    // cout<<s.name<<endl;



}
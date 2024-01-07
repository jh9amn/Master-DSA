// Give a sentence And Spilit Every Singal Ward of Sentence into New line..
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string str = "Aman is a Student";
    stringstream ss (str);
    string temp;

    while(ss>>temp){
        cout<<temp<<endl;
    }
}

#include<iostream>
using namespace std;
int main(){
 char ch;
 cout<<"enter the charactor";
 cin>>ch;
 
 int ascii = (int)ch;

 //a to z -> 97 to 122
 // A to Z -> 65 to 90

 if(ascii >= 65 && ascii <= 90){
    cout<<"UpperCase charactor "<<ascii;
 }
 else if( ascii >= 97 && ascii <= 122){
    cout<<" LowerCase charactor "<<ascii;
 }
 else{
    cout<<"not a charctor ";
 }

}



/* 
if ((ascii>=65 && ascii <=90)  || (ascii >=97 && ascii <= 122)){
 cout<<"charactor is an alphabat";
}
else {
    cout<<"charctor is not an alphabats";
}

*/
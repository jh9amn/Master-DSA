#include<iostream>
using namespace std;
int min(int a,int b){
    if(a<b) return a;
    return b;
}

int min(int a,int b,int c){
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    else return c;
    
}

// int min(int a,int b,float c){
//        if(a<=b && a<=c) return a;
//     if(b<=a && b<=c) return b;
//     else return c;
    
// }

int main(){
    cout<<min(5,6,7);
   
}
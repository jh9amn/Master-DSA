#include<iostream>
using namespace std;
void num(int n){
    // base case
    if(n==0) return;
    else { 
    cout<<n<<endl;  // work
    num(n-1);  //call
    }

}
 int main(){
 num(6);
 }
 
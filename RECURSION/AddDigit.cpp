#include<iostream>
using namespace std;
int digit(int n){
    if(n<=9 && n>=1) return n;
    return (digit(n/10) + n%10);

}
 int main(){
   int result = digit(148);
   cout<<result;

 }
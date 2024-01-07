#include<iostream>
using namespace std;
int f(int n){
    int ans = 0;
    if(n==0) {
        ans = 1;
        return ans;
    }
    else{
        f(n%10)
    }
}
int main(){
    cout<<f(2345);
}
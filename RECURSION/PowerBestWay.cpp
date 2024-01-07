#include<iostream>
using namespace std;
int pow(int a, int b){
    if(b==0) return 1;    // 2power0 = 1
    if(b==1) return a;    // 2power1 = 2
    int ans;
    if(b%2==0) {
      ans = pow(a,b/2);   // 2power8 = 2power4 * 2power4
        return ans*ans;
    }
    else 
    ans = pow(a,b/2);     //  2power9 = 2power4 * 2power4 * 2
    return ans*ans*a;
}

 int main(){
    cout<<pow(3,3);
 }
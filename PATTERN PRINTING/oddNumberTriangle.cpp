// 1
// 13
// 135
// 1357
// 13579



#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1 ; i<=n; i++){
        int a=1;
        for(int j=1; j<=i; j++){
            cout<<a;
            a+=2;
        }cout<<endl;
    }
    }



//Another Way..

// for(int i=1; i<=n; i++){
//     fo(int j=1; j<=2*i-1; j+=2){
//         cout<<j;
//     }cout<<endl;
// }



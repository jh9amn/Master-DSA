#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]= {3,5,2,0};
    int b[5]= {0,2,4,4};
    int n = sizeof(a) / sizeof(a[0]);
    int ans = 0;
    int res = 0;
    for(int i=0; i<n; i++){
        ans = ans + (a[i] - b[i]);
        if(res > ans){
            continue;
        }
        res = ans;
    }
    cout<<res;
}
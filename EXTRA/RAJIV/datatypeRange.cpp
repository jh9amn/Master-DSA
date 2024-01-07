#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x%x==1){
    if(x>=INT_MIN && x<=INT_MAX) cout<<4;
    else if(x>=LONG_MIN && x<=LONG_MAX) cout<<8;
    else if(x>=FLT_MIN  && x <= FLT_MAX ) cout<<4;
    else cout<<8;
    }
    else cout<<1;    
}
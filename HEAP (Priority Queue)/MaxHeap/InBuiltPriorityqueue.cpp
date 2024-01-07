#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int v[]= {9, 6, 1, 19, 3, 2, 8, 12, 5};
    int n = sizeof(v) / sizeof(v[0]);
    priority_queue<int> maxHp(v,v+n);
    for(auto i : v){
        cout<<i<<" ";
    }cout<<"\n";


    
}
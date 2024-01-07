// MAx Elements in the String Array

#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter The Size of String";
    cin>>n;
    string arr[n];
    cout<<"Enter the Elements in The String"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int mx = stoi(arr[0]);
    string maxS = arr[0];

    for(int i=0; i<=n; i++){
        int x = stoi(arr[i]);
        if(x>mx){  mx = x;
        maxS = arr[i];
     }
    }


    cout<<"The Elements is as"<<mx<<endl;
    cout<<"The MAx String Is Look like "<<maxS<<endl;

}

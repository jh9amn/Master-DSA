#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
 int main(){
    int arr[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    int max = INT_MIN;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
           if(arr[i][j] > max){
           max = arr[i][j];
        }
      }
    } 
     cout<<max<<" ";
    return 0;
    
     }
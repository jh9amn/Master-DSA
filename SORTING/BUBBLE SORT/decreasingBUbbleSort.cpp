/*
 Sorting In decending Order
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main(){
    int arr[] = {5,4,3,2,1};
    int n = 5;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i=0; i<n-1; i++){
        bool flag = true;
        for(int j=n-1; j>0; j--){
            if(arr[j] > arr[j-1]){
                swap(arr[j], arr[j-1]);
                flag = false;
            }
        }  if(flag == true)  break;
    }


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

 }
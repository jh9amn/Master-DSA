/*
Check if the given array is atmost Sorted.
(Elelment Are at-most one position away) 
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {4,2,7,9,8};
    int n = 5;
    int brr[5];


    // copy the arr into brr
    for(int i=0; i<n; i++){
        brr[i] = arr[i];
    }
 

   cout<<"The Given Array is ";
   for(int i=0; i<n; i++){
        cout<<brr[i]<<" ";
    }cout<<endl;
    

    // Sorting The Arr Array using Bubble sort
    for(int i=0; i<n-1; i++){
        bool flag = true;
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if(flag == true ) break;
    }


    cout<<"The Sorted Array is as ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    bool flag = true;

    for(int i=0; i<n; i++){
        if(i==0){
            if(brr[i]!=arr[i] && brr[i]!=arr[i+1]){
                flag = false;
                break;
            }
        }

        else if(i == n-1){
            if(brr[i] != arr[i] && brr[i] != arr[i-1]){
                flag = false;
                break;
            }
        }

        else{
            if(brr[i] != arr[i] && brr[i] != arr[i-1] && brr[i] != arr[i+1] ){
                flag = false;
                break;
            }
        }  

    }    

    if(flag == false) cout<<"Not Almost Sorted "<<endl;
    else cout<<"Almost Sorted "<<endl;  

    return 0;   
    
}
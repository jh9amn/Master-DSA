#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main(){
    int arr [] = {4,2,8,7,9};
    int n=5;

    cout<<"The Array Is as   ";
    for(int i=0; i<n; i++){  
        cout<<arr[i]<<" ";
    }cout<<endl;

// If it is almost Sorted Then it just need one pass to get his right place
    for(int i=0; i<n-1; i+=2){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
            // i++;
        }
    }

    cout<<"The swap Array is as   ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


// if now is not sorted the it is not almost sorted
    bool flag = true;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            flag = false;
            break;
        }
    }

    if(flag == false)  cout<<"Not Almost Sorted ";
    else   cout<<"Almost Sorted ";
    return 0;
 }


 /*

 example 1..
 4,2 9,7,8

 if(arr[i] > arr [i+1])

 2,4,7,9,8  then here 9 need one more time to get it his right place 
 that's why it is not almost sorted
 
 example 2...
 4,2,8,7,9

 if(arr[i] > arr [i+1]) then

 2,4,7,8,9
 Here,
 all the elements just need one time to get there right place...

 
 */
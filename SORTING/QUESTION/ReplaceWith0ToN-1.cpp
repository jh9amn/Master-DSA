// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;
//  int main(){
//     int arr[] = {19,12,23,8,16};
//     int n = 5;
//     vector<int> v(n,0);
//     int x = 0;

//        for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;


//     // Finding the lowest Element And the Index 
//     for(int i=0; i<n; i++){
//         int min = INT_MAX;
//         int minidx = -1;
//         for(int j=0; j<n; j++){
//             if(v[j] == 1) {
//                 continue;
//             }
//             else{  // lowest element and index
//                 if(arr[j] < min){
//                     min = arr[j];
//                     minidx = j;
//                 }
//             }
//         } 
//         arr[minidx] = x;
//         v[minidx] = 1;
//         x++;
//     }

//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
    

//  }



 // IF THE GIVEN ARRAY IN POSITIVE THEN WE DONT NEED TO USE EXTRA SPACE

 #include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 int main(){ 
    int arr[] = {19,12,23,8,16};
    int n = 5;
    // vector<int> v(n,0);
    int x = 0;

       for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    // Finding the lowest Element And the Index 
    for(int i=0; i<n; i++){
        int min = INT_MAX;
        int minidx = -1;
        for(int j=0; j<n; j++){
            if(arr[j] <= 0) {
                continue;
            }
            else{  // lowest element and index
                if(arr[j] < min){
                    min = arr[j];
                    minidx = j;
                }
            }
        } 
        arr[minidx] = -x;
        x++;
    }

    for(int i=0; i<n; i++){
        arr[i] = -arr[i] ;
        cout<<arr[i]<<" ";
    }cout<<endl;
    

 }
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main(){
     int arr[] = {2,2,2,3,3,3,3,4,4,7,7,9,9,9};
     int n = sizeof(arr)/sizeof(arr[0]);
     int low =0;
     int high = n-1;
     int target = 4;
     bool flag = false;

      while(low<=high){
        int mid = low+(high-low)/2;
             if(arr[mid] == target) {
                if(arr[mid-1] != target) {
                cout<<mid;
                flag = true;
                break;
                }
                else{
                    high = mid-1;
                }
             }
             
             else if(arr[mid] > target) high = mid-1;
             else low = mid+1;
      }

      if(flag == false)  return -1;
 }
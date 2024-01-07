#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> v;

vector<int> lowerBound(int arr[], int n , int x ){
       int low = 0;
       int high = n-1;
       int lowerBound = n;      
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] >= x){
                lowerBound = mid;
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }
        v.push_back(lowerBound);
}
         
vector<int> upperBound(int arr[], int n , int x ){
       int low = 0;
       int high = n-1;
       int upperBound = n;
      
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] > x){
                upperBound = mid;
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }
        v.push_back(upperBound);
}
    
int main(){
    int arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    lowerBound(arr,9,5); // ->> idx = 2
    upperBound(arr,9,5); // ->> idx = 6
    
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}        
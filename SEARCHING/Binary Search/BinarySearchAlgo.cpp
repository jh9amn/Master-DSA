#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    // int arr[] = {2,5,1,7,4,92,9,6,34,25};
    vector<int> v;
   
   v.push_back(1); //0
   v.push_back(2); //1
   v.push_back(4); //2
   v.push_back(8); //3
   v.push_back(6); //4 
   v.push_back(7); //5
   v.push_back(3); //6
   v.push_back(9); //7

   int n = v.size();

    cout<<"The Given array is as ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<" "; 
    }cout<<endl;

    sort(v.begin(),v.end());

       cout<<"The Sorted array is as ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<" "; 
    }cout<<endl;
    
   int target = 3;

    int low = 0 ;
    int high = n-1;
    
    // BINARY SEARCH
    int index = 0;
    bool flag = false;
    while(low <= high){
        int mid = (low+(high-low)/2);   //int mid = (low+high )/2;
        if(v[mid] == target){
        index = mid;
        flag  = true;
        break;
        }
        else if(v[mid] > target ) high = mid-1;
        else low = mid+1; 
    }  
    if(flag ==  true)  cout<<"Yes Present";
    else cout<<"NOt Present" ;
}
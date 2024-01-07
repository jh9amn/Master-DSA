// Leetcode 42

// Q.. Trapping the rain Water

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
         int n = height.size();

         //finding prev greatest element

         int prev[n];
         prev[0] = -1;
         int max = height[0];

         for(int i=1; i<n; i++){
             prev[i] = max;
            if(max < height[i])  max = height[i];
         } 

         // finding next greatet element

         int next[n];
         next[n-1] = -1;
         max = height[n-1];

         for(int i=n-2; i>=0; i--){
             next[i] = max;
             if(max < height[i])  max = height[i];
         } 

        // finding the min array
        int mini[n];
        for(int i=0; i<n; i++){
            mini[i] = min(prev[i],next[i]);
        }

        // calculating water
        int water = 0;
        for(int i=1; i<n-1; i++){
            if(height[i] < mini[i]){
            water += (mini[i] - height[i]);
        }
      }   return water;
    }


    int main(){
        vector<int> v;
        // Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    
    for(int i=0; i<v.size(); i++){
        cout<<v.at(i)<<" ";
    } cout<<endl;
  
   int water =  trap(v);

    cout<<"The trap water is as "<<water;


    }
// SELECTION SORT

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(-10);
    v.push_back(7);
    v.push_back(-1);
    v.push_back(5);
    v.push_back(8);
    v.push_back(-13);

    int n = v.size();

    cout<<"The given vector is as ";
    for(int ele: v){
        cout<<ele<<" ";
    } cout<<endl;

    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    // } cout<<endl;

    for(int i=0; i<n-1; i++){
        int min = INT_MAX;
        int minidx = -1;
        for(int j=i; j<n; j++){
    // findin the min element in the loop
            if(v[j] < min){
                min = v[j];
                minidx = j;
            }
        }
        // Swapping every min element with ith index...
        swap(v[i], v[minidx]);
    }

    cout<<"The selection sorted vector is as ";
    for(int ele: v){
        cout<<ele<<" ";
    }cout<<endl;

    //     for(int i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    // } cout<<endl;

 }
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
 using namespace std;
 void change (vector<int> &a){  // vector pass to the function 
                                // call by refrence
  a[0] = 100;
 }

 int main(){
    vector<int> v;
    v.push_back(19);
    v.push_back(20);
    v.push_back(24);
    v.push_back(29);
  
   // printing the vector
   for(int i=0; i<v.size(); i++){
    cout<<v.at(i)<<" ";
   } cout<<endl;

    change(v);

     for(int i=0; i<v.size(); i++){
    cout<<v.at(i)<<" ";
   } cout<<endl;
 }















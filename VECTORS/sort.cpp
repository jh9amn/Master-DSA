#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
vector <int> v;
 v.push_back(19);
 v.push_back(20);
 v.push_back(24);
 v.push_back(29);

 // printing the vector
 for(int i=0; i<v.size(); i++){
    cout<<v.at(i)<<" ";
 } cout<<endl;

 v.at(2) = 10;
  for(int i=0; i<v.size(); i++){
    cout<<v.at(i)<<" ";
 } cout<<endl;

 // sorting the elements in asscending order
 sort(v.begin(),v.end());
  for(int i=0; i<v.size(); i++){
    cout<<v.at(i)<<" ";
 } cout<<endl;

}
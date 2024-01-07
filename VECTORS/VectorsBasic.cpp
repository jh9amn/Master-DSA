#include<iostream>
#include<vector>
using namespace std;
int main(){
 vector<int> v;
 v.push_back(7);
 cout<<v.size()<<" ";  //1 2 3 4
 cout<<v.capacity()<<endl;   // 1 2 4 4
 v.push_back(11); 
 cout<<v.size()<<" ";
 cout<<v.capacity()<<endl;
 v.push_back(3);
 cout<<v.size()<<" ";
 cout<<v.capacity()<<endl;
 v.push_back(6);
 cout<<v.size()<<" ";
 cout<<v.capacity()<<endl;

cout<<endl;

// 7 11 3 6
cout<<v[0]<<" ";

cout<<v[1]<<" ";

cout<<v[2]<<" ";

cout<<v[3]<<" ";

;}
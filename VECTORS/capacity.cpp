#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> v;
                  //size capacity
v.push_back(36);  // 1 1 
v.push_back(24);  // 2 2
v.push_back(10);  // 3 4
v.push_back(35);  // 4 4
v.push_back(24);  // 5 8
v.push_back(11);  // 6 8
v.push_back(33);  // 7 8
v.push_back(24);  // 8 8
v.push_back(12);  // 9 16
v.push_back(38);  // 10 16
v.push_back(24);  // 11 16
v.push_back(14);  // 12 16

cout<<v.size()<<endl;

//when size and capacity are equal then after next element
// capacity increases by multiple of 2..
cout<<v.capacity()<<endl;

               //size capacity
v.pop_back();  // 6 16
v.pop_back();  // 7 16
v.pop_back();  // 8 16
v.pop_back();  // 9 16
v.pop_back();  // 10 16
v.pop_back();  // 11 16

  // after pop_back the size is decreases but the
  // capacity isnot decreases..
cout<<v.size()<<endl;
cout<<v.capacity()<<endl;

}
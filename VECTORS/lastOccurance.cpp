// find the last occurance of x 
#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<int> v;
v.push_back(19);
 v.push_back(20);
 v.push_back(24);
 v.push_back(80);
 v.push_back(26);
 v.push_back(27);
 v.push_back(80);
 v.push_back(19);

    int x = 80;
    int idx = -1  ;

 for(int i = v.size()-1; i>=0; i--){
    if(v[i] == x) {
    idx = i;
    break;
    }
 }

 cout<<idx;

}

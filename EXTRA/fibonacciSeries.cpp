#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k = 10;
    vector<int> v;
    int a = 1; 
    int b = 1;
    v.push_back(a);
    v.push_back(b);
    for(int i=0;; i++){
        int c = a+b;
        if(c>k) break;
        v.push_back(c);
        a = b;
        b = c;
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

}
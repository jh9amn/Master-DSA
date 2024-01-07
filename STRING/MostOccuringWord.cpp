#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str = "I am Aman. And I am a BCA Student.";
    stringstream ss (str);

    vector<string> v;
    int temp;
    

    while(ss>>temp){
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    int maxCount = 1;
    int count = 1;
    for(int i=1; i<v.size(); i++){
        if(v[i]==v[i-1])  count++;
        else count = 1;
        maxCount = max(maxCount , count);
    }

    count = 1;
    for(int i=1; i<v.size(); i++){
        if(v[i] == v[i-1]) count ++;
        else count = 1;
        if(count == maxCount){
            cout<<v[i]<<" "<<maxCount<<endl;
        }
    }


}
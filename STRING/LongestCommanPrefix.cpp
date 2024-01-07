// Longest Common prefix Sum
// like Flight , Flow, Flower 
// longest common Prefix Sum is Fl

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    vector<string> v;
    
    // for(int i=0; i<n; i++){
    //     string x;
    //     cin>>x;
    //     v.push_back(x);
    // }

    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");
    int n = v.size();

    // if(n==1)  return v[0];

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    string sFirst = v[0];
    string sLast = v[n-1];

    string sum = "";

    for(int i=0; i<(min(sFirst.size(),sLast.size())); i++){
        if(sFirst[i] == sLast[i]){
            sum += sFirst[i];
        }  
    }
   
   cout<<sum;
    
}
#include<bits/stdc++.h>
using namespace std; 
int main(){
    vector<int> v= {1,2,2,3,4,4,5};
    // unordered_set<int> s(v.begin(), v.end());
    // for(auto a : s){
    //     cout<<a <<" ";
    // }

    int n = v.size();
    int count = 1;
    for(int i=1; i<n; i++){
      if(v[i-1] != v[i]) v[count++] = v[i];
    }
    for(int i=0; i< n-count; i++){
        v.pop_back();
    }

    cout<<"The array without duplicate is as :";
    for(int x : v){
    cout<<x<<" ";
    }cout<<endl;

    int ss ;
    int ts;
    int a;
    // for(int i=n-1; i>=0; i--){
    //     if(v[i-1] > v[i]){
    //         a = v[i];
    //     }
    //     if(i-2 >= 0 && v[i-2] < a){
    //         secondLargest = v[i-2];
    //     }
    //     // if(v[i-3] < secondLargest){
    //     //     third = v[i-3];
    //     // }
    // }
    // cout<<a<<endl;
    // cout<<"second Largets : "<<secondLargest;

    int i = n-1; 
    while( i >= 0 ){
       if(v[i] < INT_MAX){
        a = v[i];
       }
       if(v[i-1] < a) ss = v[i-1];
       if(v[i-2] < ss) ts = v[i-2];
        i--;
    }
    cout<<"second smallest:"<<ss<<endl;
    cout<<"third smallest : "<<ts;


}
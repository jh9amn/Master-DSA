#include<iostream>
#include<stack>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {100,80,101,81,70,60,75,85};
    int n = sizeof(arr)/ sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    stack<int> st;
    int pgi[n];
    pgi[0] = -1;            // pge = previous greater element
    st.push(0);
    for(int i=1; i<n; i++){
        while(st.size()>0 && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.size() == 0)  pgi[i] = -1;
        else  pgi[i] = st.top();
        st.push(i);
    }
    // previous greater element
    for(int i=0; i<n; i++){
        cout<<pgi[i]<<" ";
    }cout<<endl;

    for(int i=1; i<n; i++){
    pgi[i] = i-pgi[i];
    }
    // stock span days
       for(int i=0; i<n; i++){
        cout<<pgi[i]<<" ";
    }cout<<endl;
}
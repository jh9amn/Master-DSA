#include<bits/stdc++.h>
using namespace std; 
int f_recursive_BS(vector<int> &v, int lo, int hi, int target){
    if(lo > hi) return -1;
    int mid = lo+(hi-lo)/2;
    if(v[mid] == target ) return mid;
    if ((v[mid] < target)) return f_recursive_BS(v,mid+1,hi,target);
    return f_recursive_BS(v,lo,mid-1,target);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<f_recursive_BS(v,0,n-1,10);
}
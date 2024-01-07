#include<iostream>
#include<vector>
using namespace std;

// This is for merging two sorted Array...
void mergeArray(vector<int> &a,vector<int> &b, vector<int> &res){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j= 0;
    int k = 0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
        if(i == n1) while(j<n2) res[k++] = b[j++];
        if(j == n2) while(i<n1) res[k++] = a[i++];
    }
} 

void mergeSort(vector<int> &v){
    int size = v.size();
    int n1 = size/2;
    int n2 = size-(size/2);
    if(size == 1) return;
    vector<int> a(n1);
    vector<int> b(n2); 
    for(int i=0; i<n1; i++) a[i] = v[i];
    for(int j=0; j<n2; j++) b[j] = v[j+n1];
    mergeSort(a);
    mergeSort(b);
    mergeArray(a,b,v);
    a.clear();
    b.clear();
}

int main(){
    int arr[] = {2,4,3,6,7,9,10,12,11,15};
    int n  = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);
     for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    // int brr[] = {1,4,6,8,10};
    // int n2 = sizeof(brr)/sizeof(brr[0]);
    // vector<int> b(brr,brr+n2);
    // vector<int> res(n1+n2);
    // merge(a,b,res);
    // for(int i=0; i<res.size(); i++){
    //     cout<<res[i]<<" ";
    // }
}
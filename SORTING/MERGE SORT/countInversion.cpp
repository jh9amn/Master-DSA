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

int countInversion(vector<int> &a, vector<int> &b){
    int count = 0;
    int j = 0;
    int i = 0;
    while(i<a.size() && j < b.size()){
        if(a[i] > b[j]) {
            count += (a.size()-i);
            j++;
        }
        else  {
            i++;
        }
    }
    return count;  
}

int mergeSort(vector<int> &v){
    int count = 0;
    int size = v.size();
    int n1 = size/2;
    int n2 = size-(size/2);
    if(size == 1) return 0 ;
    vector<int> a(n1);
    vector<int> b(n2); 
    for(int i=0; i<n1; i++) a[i] = v[i];
    for(int j=0; j<n2; j++) b[j] = v[j+n1];
    count += mergeSort(a);
    count += mergeSort(b);
    count += countInversion(a,b);
    mergeArray(a,b,v);
    a.clear();
    b.clear();
    return count;
}

int main(){
    int arr[] = {5,1,3,0,4,9,6};            // (5,1),(5,3),(5,0),(5,4),(1,0),(3,0),(9,6) this is inversion total number of inversion is 7
    int n  = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);
     for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<mergeSort(v);
   
}
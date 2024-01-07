#include<bits/stdc++.h>
using namespace std;
void f(int arr[], int i, int n){
    if(n == i) return;
    cout<<arr[i]<<" ";
    f(arr,i+1,n);
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    f(arr,0,n);
}
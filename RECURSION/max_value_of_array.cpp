#include<bits/stdc++.h>
using namespace std;
void f(int arr[], int i, int n, int max){
    if(n == i) {
        cout<<max<<endl;
        return;
    }
    if(max < arr[i]) max = arr[i];
    f(arr,i+1,n,max);
}

//another way to find max
int f2(int arr[], int i, int n){
    if( i == n) return INT_MIN;
    return max(arr[i], f2(arr,i+1,n));
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    f(arr,0,n,INT_MIN);
    cout<<f2(arr,0,n)<<" ";

}
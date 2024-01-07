// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&sortBy=submissions
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& a, int n) {
    int sum = n*(n+1)/2;
    int arr_sum = 0;
    for(int i=0; i<a.size(); i++) arr_sum += a[i];
    return sum - arr_sum;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,10};
    vector<int> v(arr,arr+1);
    cout<<missingNumber(v,10)<<endl;
}
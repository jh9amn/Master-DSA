#include<iostream>
using namespace std;
 int main(){
    int arr[] = {2,4,5,6,10,18,19,110 };
    int low = 0;
    int n = sizeof(arr) /sizeof(arr[0]);
    int high = n-1;
    int target = 17;
    bool flag  = true;
    while (low<=high){
        int mid = low+(high-low) / 2;
        if(arr[mid] == target ){
            flag = false;
            cout<<"LOwerBound "<<arr[mid-1]<<endl;  // for LowerBound
            cout<<"UppeeBound "<<arr[mid+1];        // For Upper Bound
            break;
        }
        else if(arr[mid] > target) high = mid-1;
        else low = mid+1;
    }
    if(flag ==  true) 
     cout<<"LowerBound "<<arr[high]<<endl;  // for Lower Bound
     cout<<"UpperBound "<<arr[low];         // for Upper Bound   
 }
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the Size";
    cin>>n;
    int arr[n];
    cout<<"Enter the element";
    for(int j = 0 ; j<n; j++){
        cin>>arr[j];
    }

    int max = arr[0];  // max = INT_MIN ;
     for(int i = 0; i<n; i++){
        if(max<arr[i])  {
         max = arr[i];
        }
     }
        cout<<"The max Element is as "<<max;
     
     return 0;
}
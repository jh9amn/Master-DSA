#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,4,1,7,6,5,7,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){ 
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int nge[n];
    for(int i=0; i<n; i++){
      nge[i] = -1;
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
            nge[i] = arr[j];
            break;
            }
        }
    }
      for(int i=0; i<n; i++){
        cout<<nge[i]<<" ";
    }
}
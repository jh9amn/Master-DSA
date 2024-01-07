// BUBBLE SORT ALGORITHM

#include<iostream>
using namespace std;
int main(){

    int arr[] = {2,1,4,3,5,7};
    int n = 6;

cout<<"The Given Array Is As ";
   for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    for(int i=0; i<n-1; i++){
        bool flag = true;
        for(int j = 0; j<n-1-i; j++){  // because every pass itration decreased by 1.
            if(arr[j] > arr [j+1]){
                // int temp = arr[j];
                // arr [j] = arr[j+1];
                // arr [j+1] = temp;
                swap(arr[j],arr[j+1]);
                flag = false;
            }
        }
    if(flag == true) break;
    }

cout<<"The Sorted Array Is as ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

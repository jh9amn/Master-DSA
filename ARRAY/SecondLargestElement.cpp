// Second Largest Element
#include<iostream>
using namespace std; 
int main(){
    int n;
    cout<<"enter The Size";
    cin>>n;

    int arr[n];
     
    cout<<"Enter the elemsnt of Array";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int max = arr[0];
    int smax = arr[0];
   
 
    // For max Element
    for(int j=0; j<n; j++){
        if(max<arr[j]) max = arr[j];
    }

    

    // For Second MAx Element
     for(int i = 0; i<n; i++){ 
        if (arr[i]!=max && smax < arr[i]){
            smax = arr[i];
        }
     }
     cout<<"Second largest Element is as"<<smax;
}


#include<iostream>
using namespace std;
int main(){
    cout<<"Entre the size of Squre Matrix"<<endl;
    int n; 
    cin>>n;
    int arr[n][n];


    cout<<"Enter The Elements ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"The Diagonal Eleemnt is as"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           if(i+j == n-1 || i==j)
            cout<<arr[i][j]<<" ";    
        else
            cout<<" ";
        } cout<<endl;
    }  return 0;
}



 
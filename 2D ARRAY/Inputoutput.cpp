#include<iostream>
using namespace std;
 int main(){
    int m,n;
    cout<<"Enter the numbers of rowa ";
    cin>>m;
    cout<<"Enter the Numbers of column ";
    cin>>n;
    int arr[n][n];

    // for n=inputing from User
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    // for outputting from user
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
 }
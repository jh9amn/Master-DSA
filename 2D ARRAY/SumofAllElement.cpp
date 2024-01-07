#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,m;
    cout<<"enter the Rows";
    cin>>n;
    cout<<"Enter the columns";
    cin>>m;

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           sum += arr[i][j];
        }
    }   cout<<"the sum of Elements id as "<<sum;
}
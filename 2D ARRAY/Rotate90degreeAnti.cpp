/* 
Input 1:      transpose then rotate
1 2 3  -->>  1 4 7
4 5 6        2 5 8
7 8 9        3 6 9
Output 1:
3 6 9
2 5 8
1 4 7
*/


#include<iostream>
using namespace std;
int main(){

    int n,m;
    cout<<"Enter the Rows"<<endl;
    cin>>n;
    cout<<"Entre the column"<<endl;
    cin>>m;
    int arr[n][m];

    cout<<"Enter The Elements of matrix"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    // transpose

    int trr[m][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            trr[i][j] = arr[j][i];
        }
    }

    cout<<"The Given matrix is as"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    cout<<"the transpose matrix is as"<<endl;
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<trr[i][j]<<" ";
        }cout<<endl;
    }

    cout<<"90 Degree Anti ClockWise Matrix"<<endl;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
            cout<<trr[i][j]<<" ";
        }cout<<endl;
    }
}


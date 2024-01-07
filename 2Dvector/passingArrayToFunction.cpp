#include<iostream>
#include<vector>
using namespace std;


// passing 1D Array tO the Function

void changeArray(int a[]){
  a[1] = 5;
}

 int main(){
    int arr[3] = {1,2,3};
    changeArray(arr);

    for(int i=0; i<3; i++){
    cout<<arr[i]<<" ";
    }
 }




 // Passing 2D Array To the Function

 void Change2DArray(int a[3][3]){
    a[1][2] = 10;
    a[2][2] = 20;
 }

 int main(){
    int arr[3][3] = {{1,2,4},{5,6,7},{8,9,10}};

    Change2DArray(arr);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

 }

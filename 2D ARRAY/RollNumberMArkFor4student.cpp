#include<iostream>
using namespace std;
int main(){
    int arr[2][4];
     for(int i=0; i<2; i++){  // i is for roll numbers
        for(int j=0; j<4; j++){   // j is for student marks
            cin>>arr[i][j];
        }
     }

    // for printing the student roll numbers and marks
      for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
     }
}
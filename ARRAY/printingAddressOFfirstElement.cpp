/* 
When */


#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,6,78,4,2,4};
    int *ptr = arr;   // Both lines indicate same 1st element address of array
    int *ptr2 = &arr[0];   // Both lines indicate same 1st element address of array
    cout<<ptr<<endl;   //0x61fee8
    cout<<ptr2<<endl;   //0x61fee8
    cout<<*ptr<<endl;  //3
    cout<<*ptr2<<endl;  // 3

    // pointer has ability to modefy and print all elements of array
    for(int i = 0;i<6; i++){
        cout<<ptr[i]<<" ";  // 3 6 78 4 2 4
    } cout<<endl;

    // pointer has ability to modify it
    ptr[0] = 1000;
    for(int i = 0;i<6; i++){
     cout<<ptr[i]<<" ";  // 1000 6 78 4 2 4
    }
    }
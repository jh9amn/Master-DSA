/* 
Pointer has the Ability to Print The Element Of Array
as Well as Address OF All Elements of Array*/


#include<iostream>
using namespace std; 
int main(){
    int arr [] = {2,34,5,6,7,3,5,2};
    int size  = sizeof(arr)/sizeof(arr[0]);
    int *ptr = arr;

    // print the address of 1st Elements of Array
    cout<<ptr<<endl;        // 0x61fee0 
    cout<<&arr[0]<<endl;    // 0x61fee0
    cout<<arr<<endl;        // 0x61fee0
    cout<<ptr[0]<<endl;     // 2

    // pointer has ability to print the elements of array
    cout<<"The Elements of array is as ";
        for(int i = 0; i<size; i++){
         cout<<ptr[i]<<" ";   // 2 34 5 6 7 3 5
    }       cout<<endl;
    
    

    // // We can print address of elements of array
    // cout<<"The Address of Element of Array is as "<<endl;
    //     for(int i = 0; i<size; i++){
    //         cout<<&ptr[i]<<" ";   //0x61fee0 0x61fee4 0x61fee8 0x61feec 0x61fef0 0x61fef4 0x61fef8 0x61fefc
    //     }


    // Pointer the also the Ability to mOdify the VAlue of element of array

     ptr[0] = 100;    // a[0]th value using pointer

    cout<<"The Elements of array is as ";
        for(int i = 0; i<size; i++){
         cout<<ptr[i]<<" ";   // 2 34 5 6 7 3 5
    }   cout<<endl;


    // One More Way to Printing the array using pointer
    cout<<"Array is As using pointer "<<endl;
    for(int i = 0; i<size; i++){
        cout<<*ptr<<" ";
        ptr++;  // at last ptr not indicating the array
      } cout<<endl;
    
    ptr = arr; // ptr is pointig hte 1st element

   // updating elements of array
    *ptr = 8;
    ptr++;
    *ptr = 9;
    ptr--;

    cout<<" One More Another Way print Array is using pointer "<<endl;
     for(int i = 0; i<size; i++){
        cout<<*ptr<<" ";  // cout<<i[ptr]<<" ";  cout<<i[arr]<<" ";
        ptr++; 
      } cout<<endl;

       ptr = arr; // ptr is pointig hte 1st element

}


#include<iostream>
using namespace std;
int main(){
    int  arr[6] = {2,5,3,7,8,9};
    //another way
    int arr[] = {3,68,58,43,25,34,44};
    cout<<arr[0]<<" ";
    cout<<arr[5];




int arr[10];

//takin inputs from users
cout<<"Enter the elements of array";
for(int i = 0; i <= 9; i++){
    cin>>arr[i];
}

// printing the outputs
cout<<"The elements of Array are as";
for(int i = 0; i<=9; i++){
    cout<<arr[i];
}

}


/* When We pass Array in A function We pass 
the Address of the First Element Present
in the Array*/


#include<iostream>
using namespace std; 
void display(int a[],int size){  
    cout<<"The Array is As ";
 for(int i = 0; i<size ; i++){
    cout<<a[i]<<" ";
 } cout<<endl;
}

void change(int b[],int size){
  b[0] = 100;
}

int main(){
    int arr[] = {2,4,6,8,9,4,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The Size iS "<<size<<endl;
    display(arr,size);  // passing a array as an argument give address of 1st element:
    change (arr,size);
    display(arr,size);
    return 0;
}
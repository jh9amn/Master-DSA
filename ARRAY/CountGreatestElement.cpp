// count the number of elements greater to the 
// particular given element..

#include<iostream>
using namespace std;  
int main(){
    int n;
    cout<<"Enter The Size";
    cin>>n;

    int arr[n];

    cout<<"Enter The Elements of Array";
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }

    int ele;
    cout<<"Enter the Element to compare";
    cin>>ele;
    int count = 0 ;

    for(int j = 0; j < n; j++){
        if (ele < arr[j] )  count++;
    }
    cout<<"No OF Element Are Greater to the Particular Element "<<count;
}

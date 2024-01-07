#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,5,8,9,10,15,16,20};
    int lowerBound = 11;
    int n = sizeof(arr) / sizeof(arr[0]);

    bool flag = false;
    int index = 0;

    for(int i=0; i<n; i++){
        if( arr[i] > lowerBound ){
            cout<<arr[i-1]<<endl; // lower Bound
            cout<<arr[i];   // Upper Bound
            break;
        }
    }
}


/* lowerBoud Of 10 is 9
and UpperBound of 10 is 15..
*/
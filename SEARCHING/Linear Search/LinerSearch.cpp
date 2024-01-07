// LINER SEARCHH

#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2,5,1,7,4,92,9,6,34,25};
    int target = 9;
    int n = 10;

    bool flag = false;
    int index = 0;

    for(int i=0; i<n; i++){
        if( arr[i] == target ){
            index = i;
            flag = true;
             break;
        }
    }
   if(flag == true) cout<<index;
   else cout<<"Not Found";
}


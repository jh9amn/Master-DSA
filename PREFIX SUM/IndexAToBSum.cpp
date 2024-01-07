#include<iostream>
using namespace std ;
 int main(){
   int arr[]={2,5,2,5,2,8,3,2,8,4,8};
   for(int i=1; i<11; i++){
    arr[i] = arr[i-1]+arr[i];
   }

   // prefix sum Form index A to B then 
   // formula prefix[b] - prefix[a-1];
   // index 3 to index 6 ka sum
    int sum ;
   for(int i=3; i<6; i++){
     sum  = arr[6] - arr[3-1];   
   }cout<<sum;
 }
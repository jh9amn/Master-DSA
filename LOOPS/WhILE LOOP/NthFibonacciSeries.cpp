/*Print The Nth Fibonacci Series

Series = 1 1 2 3 5 8 13 21 34 55 89 ....
formula : intialization
          a=1 
          b=1 
          sum = 0

          sum = a+b;
          a=b;
          b=sum;
          cout<<b or sum;
*/


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the Nth Term Number";
    cin>>n;

    int a = 1, b = 1, sum = 0;
    for(int i=1; i<=n-2;  i++){
        sum = a+b;
        a=b;
        b=sum;

    }
    cout<<b;   //because b == sum and 1 too


}
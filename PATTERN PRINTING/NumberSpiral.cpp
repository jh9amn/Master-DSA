#include<iostream>
using namespace std;
int main(){
     cout<<"Enter the size";
     int n;
     cin>>n;


        // 11111
        // 12222
        // 12333
        // 12344

     for(int i=1; i<=2*n-1; i++){
        for(int j=1; j<=2*n-1; j++){
            int a = i; 
            int b = j;

            if(a>n) a = 2*n-i;
            if(b>n) b = 2*n-j;
            int x = min(a,b);


            // 1111111
            // 1222221
            // 1233321
            // 1234321
            // 1233321
            // 1222221
            // 1111111
              cout<<x; 


            // 4444444
            // 4333334
            // 4322234
            // 4321234
            // 4322234
            // 4333334
            // 4444444 
            // cout<<n-x+1;
           
        }  cout<<endl;
     }
}
// 123456789
// 1234 6789
// 123   789
// 12     89
// 1       9


// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
// 1 2 3 4 5 6 7 8 9   11 12 13 14 15 16 17 18 19  
// 1 2 3 4 5 6 7 8       12 13 14 15 16 17 18 19   
// 1 2 3 4 5 6 7           13 14 15 16 17 18 19    
// 1 2 3 4 5 6               14 15 16 17 18 19     
// 1 2 3 4 5                   15 16 17 18 19      
// 1 2 3 4                       16 17 18 19       
// 1 2 3                           17 18 19        
// 1 2                               18 19

#include<iostream>
using namespace std;
int main(){
    int n;
     cout<<"Enter the Number";
     cin>>n;
      for(int u = 1; u<=2*n-1; u++){
        cout<<u<<" ";
     }  cout<<endl;


     int m = n-1;
     int nsp = 1;

     for(int i = 1; i<=m ; i++){
        int a = 1;
         for(int j = 1; j<=m+1-i; j++){
            cout<<a<<" ";
            a++;
         }

         //spaces
         for(int k=1; k<=nsp; k++){
            cout<<" "<<" ";
            a++;
         }
         nsp+=2;
         // numbers
         for(int j=1; j<=m+1-i; j++){
            cout<<a<<" ";
            a++;
         }
         cout<<endl;
  }
}
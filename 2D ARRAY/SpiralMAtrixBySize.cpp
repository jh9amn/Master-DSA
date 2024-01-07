/*
Given a positive integer n, generate a n x n matrix filled with elements from 1 to n2 in spiral order.
Input 1: n = 3
Output 1: [[1,2,3],[8,9,4],[7,6,5]]
Input 2: n = 1
Output 2: [[1]]
*/


// not Completed
#include<iostream>
using namespace std;
 int main(){
    int n;
    cout<<"Enter the size of Matrix"<<endl;
    cin>>n;

   //  cout<<"Enter the Elements of matrix"<<endl;
    int a[n][n];

    int ans = 1;

   //  for(int i=0; i<n; i++){
   //    for(int j=0; j<n; j++){
   //       cin>>a[i][j];
   //    }
   //  }

   // cout<<"The given Matrix is as"<<endl;
   //  for(int i=0; i<n; i++){
   //    for(int j=0; j<n; j++){
   //       cout<<a[i][j];
   //    }cout<<endl;
   //  }

    int minr = 0, minc = 0;
    int maxr = n-1, maxc = n-1;

   

   while(ans<=n*n){

       while(minr<=maxr  && minc <= maxc){
     
      for(int j=minc; j<maxc; j++){
         a[minr][j] = ans++ ;
         cout<<a[minr][j]<<" ";
         minr++;  
      }

      for(int i=minr; i<maxr; i++){
         a[i][maxc] = ans++; 
         cout<< a[i][maxc] <<" "; 
         maxc--;
      }

      for(int j=maxc; j>=minc; j--){
         a[maxr][j] = ans++;
         cout<< a[maxr][j]<<" ";
         maxr--;
      }

      for(int i=maxr; i>=minr; i--){
         a[i][minc] = ans++;
         cout<<a[i][minc]<<" ";
         minc++;
      }
     }
   }
  
   //  for(int i=0; i<n; i++){
   //    for(int j=0; j<n; j++){
   //       cout<<a[i][j]<<" ";
   //    }cout<<endl;
   //  }

    }


    
 
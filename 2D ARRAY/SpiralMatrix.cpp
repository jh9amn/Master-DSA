/*
Input:

1 2 3
4 5 6
7 8 9

Output is as: 1 2 3 6 9 8 7 4 5
*/
 
 //  Sprial Matrix
 

 #include<iostream>
 using namespace std;
 int main(){
    cout<<"Enter the row of matrix ";
    int n;
    cin>>n;
    cout<<"Enter the column of matrix ";
    int m;
    cin>>m;
 

   int arr[n][m];   // inputting in the 1st matrix
   cout<<"Enter the Elements of matrix"<<endl;;
   for(int i =0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>arr[i][j];
    }
   }


    // the given first matrix is as
   cout<<"The matrix is as "<<endl;
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cout<<arr[i][j]<<" ";
    }cout<<endl;
   }
   cout<<endl;


   int minr = 0, minc = 0;
   int maxr = n-1, maxc = m-1;

   while(minr<=maxr  && minc <= maxc){

        if(minr > maxr || minc > maxc)  break;
        // left -> right  (column traversal)
        for(int j=minc; j<=maxc; j++){
            cout<<arr[minr][j]<<" ";
        } minr++;

        if(minr > maxr || minc > maxc)  break;
        // up -> down   (row traversal)
        for(int i=minr; i<=maxr; i++){
            cout<<arr[i][maxc]<<" ";
        }maxc--;

        if(minr > maxr || minc > maxc)  break;
        // right -> left    (column traversal)
        for(int j=maxc; j>=minc; j--){
            cout<<arr[maxr][j]<<" ";
        }maxr--;

        if(minr > maxr || minc > maxc)  break;
        // down to up   (row traversal)
        for(int i=maxr; i>=minr; i--){
            cout<<arr[i][minc]<<" ";
        }minc++;
   }
 }

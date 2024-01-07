/*
The matrix is as
1 2 3
4 5 6
7 8 9

the Wave form of the MAtrix is as
1 2 3
6 5 4
7 8 9
*/
 
 
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

    cout<<"the Wave form of the MAtrix is as "<<endl;

    for(int i=0; i<n; i++){
         if(i%2==0){
            for(int j=0; j<m; j++){
             cout<<arr[i][j]<<" ";
            }
          } 
           else{
                for(int j=n-1; j>=0; j--){
                    cout<<arr[i][j]<<" ";
                }
            }   cout<<endl;
        } 
    }


 

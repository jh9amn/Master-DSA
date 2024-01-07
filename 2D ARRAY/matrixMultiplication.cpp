 #include<iostream>
 using namespace std;
 int main(){
    cout<<"Enter the row of 1st matrix";
    int n;
    cin>>n;
    cout<<"Enter the column of 1st matrix";
    int m;
    cin>>m;

    cout<<"Enter the row of 2nd matrix";
    int x;
    cin>>x;
    cout<<"Enter the column of 2nd matrix";
    int y;
    cin>>y;

    if(m==x){  // 1st column and 2nd row equal then

   int arr[n][m];   // inputting in the 1st matrix
   cout<<"Enter the Elements of 1st matrix"<<endl;;
   for(int i =0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>arr[i][j];
    }
   }


   int brr[x][y];   //inputting in the 2nd matrix
   cout<<"Enter the Elements of 2nd matrix"<<endl;;
   for(int i =0; i<x; i++){
    for(int j=0; j<y; j++){
        cin>>brr[i][j];
    }
   }

    // the given first matrix is as
   cout<<"The 1st matrix is as "<<endl;
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cout<<arr[i][j]<<" ";
    }cout<<endl;
   }
   cout<<endl;

    // the given 2nd matrix is as
   cout<<"The 2nd matrix is as "<<endl;
   for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
        cout<<brr[i][j]<<" ";
    }cout<<endl;
   }
   cout<<endl;

    // performing matrix multiplication
   int c[n][y];
   for(int i=0; i<n; i++ ){
    for(int j=0; j<y; j++){
        c[i][j] = 0;
        for(int k=0; k<x; k++){  // for travesing in the first row and column
        c[i][j] += arr[i][k] * brr[k][j];
     } 
    }
   }

    // after multiplication the matrix is as
   cout<<"The multiply of matrix is as "<<endl;
   for(int i=0; i<n; i++){
    for(int j=0; j<y; j++){
        cout<<c[i][j]<<" ";
    }cout<<endl;
   }
   cout<<endl;
 }

    else{  // if 1st column and 2nd row does not equal
        cout<<"The Matrix Multuplication can't performed ";
    }
 }
//    1
//   121
//  12321
// 1234321

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the Size of Number Pyramid";
    cin>>n;

    for(int i = 1; i<=n; i++ ){
        for(int j=1; j<=n-i; j++){   // printing  Spaces
            cout<<" ";
        }
        for(int k = 1; k<=i; k++){  // Printing Left side of number Triangle 
            cout<<k;
        }  

        //Printing Right Side of Number Triangle
        for( int q=i-1; q>=1; q--){
            cout<<q;
        }
        cout<<endl;
        
    }
}

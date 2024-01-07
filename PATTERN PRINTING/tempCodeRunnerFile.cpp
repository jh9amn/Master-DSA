//     1
//    12
//   123
//  1234
// 12345


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size";
    cin>>n;

    for(int i=1; i<=n; i++){
        
        //printing Spaces
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        
        //Printing Number
        for(int k=1; k<=i; k++){
            cout<<k;
        } cout<<endl;
    }
}


//Another Approach
//This Approach Not work every time..

// #include<iostream>

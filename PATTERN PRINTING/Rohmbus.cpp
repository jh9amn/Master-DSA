//     *****
//    *****
//   *****
//  *****
// *****

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size";
    cin>>n;

    for(int i=1; i<=n; i++){

            //Printing Spaces
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }

        //Printing Star Rohmbus
        for(int k=1; k<=n; k++){
            cout<<"*";
        } cout<<endl;
    }
}

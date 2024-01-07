//     *
//    ***
//   *****
//  *******
// *********


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(int k=1; k<=2*i-1; k++){
            cout<<"*";
        }
        cout<<endl;
    }
}


// Another best Approach to Do this..

// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the Size";
//     cin>>n;
//     int nst = 1;
//     int nsp = n-1;

//     for(int i=1; i<=n; i++){

//         // Printing Spaces
//         for(int j=1; j<=nsp; j++){
//             cout<<" ";    
//         }
//          nsp--;
//          // printing Star
//         for(int k=1; k<=nst; k++){
//             cout<<"*";
//         }
//             nst+=2;
//         cout<<endl;
//  }
// }

// //One More Another Appproach 
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Entre the size of Star Triangle";
//     cin>>n;

//     for(int i=1; i<=n; i++){
     
//      // Printing Right Side OF Spaces
//      for(int j=1; j<=n-i; j++){
//         cout<<" ";
//         }

//      for(int k=1; k<=i; k++){
//         cout<<"*";
//      }

//      for(int q=i-1; q>=1; q--){
//         cout<<"*";
//     }   cout<<endl;
    

//     }  
// }


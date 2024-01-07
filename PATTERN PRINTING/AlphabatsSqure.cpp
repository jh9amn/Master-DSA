/*
A B C D E
A B C D E
A B C D E
A B C D E
A B C D E
*/


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n;  j++){
            cout<<(char)(j+64)<<" ";
        } cout<<endl;
    }
}
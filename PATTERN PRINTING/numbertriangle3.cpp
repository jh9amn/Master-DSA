// 12345
// 2345
// 345
// 45
// 5




#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
                cout<<j;
        }  cout<<endl;
    }
}
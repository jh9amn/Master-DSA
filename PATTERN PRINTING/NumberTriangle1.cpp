#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enetr the Size";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j;
        }cout<<endl;
    }
}

/*
1
12
123
1234
12345
*/




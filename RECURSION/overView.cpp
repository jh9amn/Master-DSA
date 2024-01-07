#include<iostream>
using namespace std;
void fun(int n){
    if(n==0) return;
    else cout<<"Hello Aman"<<endl;
     cout<<" n = "<<n<<endl;
    fun(n-1);
}

int main(){
    int n;
    cout<<"Enter The Size ";
    cin>>n;
    fun(n);
}
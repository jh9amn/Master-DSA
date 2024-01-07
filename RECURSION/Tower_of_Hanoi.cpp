#include<iostream>
using namespace std;
void f(int n, char a, char b, char c){
    if(n==0) return;
    f(n-1,a,c,b);  // a -> source , c -> helper, b -> destination
    cout<<a<<" -> "<<c<<endl;
    f(n-1,b,a,c);  // b -> source , a -> helper, c -> destination;
}
int main(){
    int n;
    cin>>n;
    f(n,'A','B','C');
}
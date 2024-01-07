#include<iostream>
using namespace std;
int main(){
int a,b;
char op;
cout<<"Enter the operation ";
cin>>a>>op>>b;

// Using if condition
// if(op=='+'){
//     cout<<a+b;
// }
// if(op=='-'){
//     cout<<a-b;
// }
// if(op=='*'){
//     cout<<a*b;
// }
// if(op=='/'){
//     cout<<a/b;
// }
// if(op=='%'){
//       cout<<a%b;
// }



//using switvh statement

switch (op){
    case '+':
        cout<<a+b;
        break;
    case '-':
        cout<<a-b;
        break;
    case '*':
        cout<<a*b;
        break;
    case '/':
        cout<<a/b;
        break;    
    case '%':
        cout<<a%b;
        break;
}
 
}
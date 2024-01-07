// ORINTIING PASCAL TRIANGLE BUT
// THIS NOT THE EFFECTIVE WAY..


#include<iostream>
using namespace std;

int factorial(int n){   // USING TO FIND THE FACTORIAL
    int fact = 1;
    for(int i=1; i<=n ; i++){
            fact *= i;
        }  
      return fact;
}

int pascalTriangle(int a, int b){
  int fact = factorial(a)/(factorial(b)*factorial(a-b));    //USING TO 
  return fact;
}


int main(){
    int n;
    cout<<"Enter The Size ";
    cin>>n;
    for(int i=0 ;i<=n; i++){
        for(int j=0 ;j<=i; j++){
                cout<<pascalTriangle(i,j);
        } cout<<endl;
    }
   
}
#include<iostream>
using namespace std;

// Using Function
int power(int a, int b){
    if(a==0 || b==0) {
        cout<<"Not Defined "<<endl; 
        return -100;
    }
    int p =1;
    for(int i=1; i<=b; i++){
        p *= a;
    }
    return p;
} // T.C = O(b) and Space Complexcity = O(1) 


// Using Recursion
int powRecursion(int a, int b){
    if(b == 0) return 1;
    return  a* powRecursion(a,b-1);
} // T.C = O(b) and Space Complexcity = O(b) Stack Frame


 int main(){
cout<<power(3,5)<<endl;   // function 
cout<<powRecursion(5,2);  // recursion 
 }

//  So, Iterative Fuction is much Better than Recursive Function


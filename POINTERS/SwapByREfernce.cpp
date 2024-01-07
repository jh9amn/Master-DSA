#include<iostream>
using namespace std;
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
    
}

int main(){
    int a = 6;
    int b = 8;
    
    swap(&a,&b);
    cout<<"a = "<<a<<"\n"<<"b = "<<b;
}


//Anpther Way

// #include<iostream>
// using namespace std;
// void swap(int &x, int &y){
//     int temp = x;
//     x = y;
//     y = temp;
//     return;
    
// }

// int main(){
//     int a = 6;
//     int b = 8;
    
//     swap(a,b);
//     cout<<"a = "<<a<<"\n"<<"b = "<<b;
// }



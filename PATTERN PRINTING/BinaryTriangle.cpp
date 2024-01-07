// 1     /* NOTE: when there is i and j mean row anf column 
// 01       both are even or both are odd then 1 is printed otherwise 0..
// 101      and there is one more condition that (the sum of two even number or two
// 0101      odd number gives always even) .. so we print that if (i+j) == 0 then print 1 
// 10101     else print 0.....Method used in 2nd Approach  */


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size";
    cin>>n;
    int a=0; //we can write any value of a here

    for(int i=1; i<=n; i++){
        if(i%2!=0) a=1;  //when row numberis odd
        else a=0;   //when row number is even

        for(int j=1; j<=i; j++){
            cout<<a<<" ";
            //flipping
            if(a==1)  a=0;
            else      a=1;
        } cout<<endl;
    }
}


    //Another Way to Do this
//     #include<iostream>
//     using namespace std;
//     int main(){
//         int n;
//         cout<<"Enter the size";
//         cin>>n;
    

//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             if((i+j)%2==0)  cout<<1<<" ";
//             else cout<<0<<" ";
//         }  cout<<endl;
//     }
// }

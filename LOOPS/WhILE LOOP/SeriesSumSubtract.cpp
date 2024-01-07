/*QUES.. PRINT THE SUM OF THIS SERIES:
         1-2+3-4+5-6+7-......'N'
*/

#include<iostream>
using namespace std;
int main(){
    int n;
    int sum = 0;
    cout<<"enter the number";
    cin>>n;

    // for(int i=1; i<=n; i++){
    //     if(i%2!=0){
    //         sum = sum+i;
    //     }else {
    //         sum = sum-i;
    //   }
    // }
    // cout<<sum;

    //Here Another Approach 
    if(n%2==0){
        cout<<(-n/2)<<endl;
    }
    else {
        cout<<(-n/2)+n<<endl;
    }  //EXPLAINATION DOWN
    return 0;

}

//Another Way to Do this ....

// CASE 1:

/* if the input is even like 8 then we observe that
(1-2)+(3-4)+(5-6)+(7-8)...
(-1)+(-1)+(-1)+(-1)
=-4
means n=8
then Alternate sum = -(n/2)

  CASE 2:

or if the input is 0dd like 7 then we observe that
(1-2)+(3-4)+(5-6)+7....
(-1)+(-1)+(-1)+7
-3+7
=4

mean n=7
then alternate sum = -(n/2)+n*/

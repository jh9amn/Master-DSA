#include<iostream>
using namespace std;

int HCF(int x,int y){
    int hcf=1;
    for(int i=min(x,y); i>=1; i++){
        if(x%i==0 && y%i==0){
            hcf = i;
        }
    }
return hcf;
}

    
int main(){
    int a,b;
    cout<<"enter the two number for HCF";
    cin>>a>>b;
 int h = HCF(a,b);
  cout<<"The Comman Factor Is as::"<<h;
}



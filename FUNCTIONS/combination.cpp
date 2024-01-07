// COMBINATION = n!/r! - (n-r)!

#include<iostream>
using namespace std;
int combi(int x){
     int fact = 1;
    for (int i=1; i<=x; i++){  
        fact = fact * i;   
    }
        return fact;   
}

int main(){
    int n;
    cout<<"Enter the n";
    cin>>n;
    int r;
    cout<<"Enter the Value of r";
    cin>>r;
    int nfact = combi(n);
    int rfact = combi(r);
    int nrfact = combi(n-r);

    cout<<"combination = "<< nfact/(rfact*nrfact);

}

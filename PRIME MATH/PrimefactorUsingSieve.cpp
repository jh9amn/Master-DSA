 #include<iostream>
 #include<cmath>
 using namespace std; 
 void primeFactor(int n){
    int spf[100] = {0};
    for(int i = 2; i<=n; i++){
        spf[i] = i;
    }

    for(int i=2; i*i <= n; i++){   // here i <= sprt(n) -> i*i = n
        if(spf[i]==i){
            for(int j=i*i; j<=n; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
 }
 int main(){
    primeFactor(36);
 }
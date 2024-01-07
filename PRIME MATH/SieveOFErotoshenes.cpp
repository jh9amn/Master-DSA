#include<iostream>
#include<cmath>
using namespace std;
void primeSieve(int n){
    int prime[100] = {0};
    int count = 0;
    for(int i = 2; i<=sqrt(n); i++){   
        if(prime[i] == 0){
            for(int j = i*i; j<=n; j+=i){
                prime[j] =1;
            }
        }
    }
    for(int i = 2; i<=n; i++){
        if(prime[i] == 0){
            count++;
            cout<<i<<" ";
        }
    }cout<<endl;
      cout<<count;
}

int main(){  
     primeSieve(60);
}




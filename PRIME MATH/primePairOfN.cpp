    #include<iostream>
    #include<bits/stdc++.h>
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
    vector<int> v;
    for(int i = 2; i<=n; i++){
        if(prime[i] == 0){
            v.push_back(i);
        }
    }
     for(int i=0; i<n; i++){
         cout<<v[i]<<" ";
    } 
}

    int main(){
    int n = 10;
     primeSieve(n);
    //  vector<int> v =

}
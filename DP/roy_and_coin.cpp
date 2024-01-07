#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> f(n+1,0);
    int m;
    cin>>m;
    vector<int> l(n+1,0);
    vector<int> r(n+1,0);
    // for(int i=0; i<m; i++){
    //     int L,R;
    //     cin>>L>>R;
    //     l[L]++;
    //     r[R]++;
    // }

    // f[1] = l[1];
    // for(int i=2; i<=n; i++){
    //     f[i] = l[i] - r[i-1] + f[i-1];
    // }

    // this is the optimised way for f vector to find
    for(int i=0; i<m; i++){
        int L,R;
        cin>>L>>R;
        f[L]++;
        f[R+1]--;
    }
    for(int i=1; i<f.size(); i++){
        f[i] = f[i] + f[i-1];
    }

    // Creating c vector
    vector<int> c(10000005,0);
    for(int i=0; i<=n; i++){
        int coins = f[i];
        c[coins]++;
    }

    // suffix sum
    for(int i=c.size()-1; i>=0; i--){
        c[i] = c[i] + c[i+1];
    }

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<c[num]<<"\n";
    }

}

/*
Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2


OUtput
6
0
0
4
*/
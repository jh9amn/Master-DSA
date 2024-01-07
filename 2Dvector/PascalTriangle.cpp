#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> generate(int numRows) {

        int n = numRows;

        vector<vector<int>> v;

        for(int i=1; i<=n; i++){
            vector<int> a(i);
            v.push_back(a); 
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(i==0 || j==i)
                    v[i][j] = 1;
                else
                    v[i][j] = (v[i-1][j] + v[i-1][j-1]); 
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
               cout<<v[i][j]<<" ";
            }cout<<endl;
        }

        return v;
    }


int main(){

     vector<vector<int>> v = generate(2) ;

        cout<<"The Pascal Triangle is as ";
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<=i; j++){
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }
        return 0;
}
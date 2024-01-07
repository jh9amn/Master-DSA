#include<iostream>
#include<vector>
#include<algorithm>
// #define ll long long int;
using namespace std;
bool cmp(int a, int b){
    return a>b;         // decending Order
}
int minCost(vector<long long> &vertical, vector<long long>& horizontal, int n, int m){
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(),horizontal.end(), cmp);
    long long cost = 0;
    int hori_count = 1;
    int ver_count = 1;
    int v = 0;
    int h = 0;

    while(v < vertical.size() && h < horizontal.size()){
        if(vertical[v] > horizontal[h]){
            cost = cost+vertical[v]*ver_count;
            hori_count++;

            v++; 
        }
        else{
            cost = cost+horizontal[h]*hori_count;
            ver_count++;

            h++;
        }
    }

    while(v < vertical.size()){
            cost = cost+vertical[v]*ver_count;
            hori_count++;

            v++; 
        }

    while(h < horizontal.size()){
        cost = cost+horizontal[h]*hori_count;
            ver_count++;

            h++;
    }
    return cost;

}


int main(){
    int m,n;
    cout<<"enter the length,breadth : ";
    cin>>m>>n;

    vector<long long> vertical;
    vector<long long> horizontal;


    for(int i=0; i<m-1; i++){
        long long x;
        cin>>x;
        vertical.push_back(x);
    }

    for(int i=0; i<n-1; i++){
        long long x; 
        cin>>x;
        horizontal.push_back(x);
    }

    cout<<"The Minimum cost to cut a board into Squre "<<(minCost(vertical,horizontal,n,m));

} 

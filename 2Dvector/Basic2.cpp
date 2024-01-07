// vector in vector

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(14);
    v1.push_back(15);
    v1.push_back(17);

    vector<int> v3;
    v3.push_back(15);
    v3.push_back(16);
    v3.push_back(17);
    v3.push_back(18);
    v3.push_back(20);
    v3.push_back(22);

    vector<int> v2;
    v2.push_back(15);
    v2.push_back(16);
    v2.push_back(17);
    v2.push_back(18);
    v2.push_back(20);
    v2.push_back(22);

    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
}

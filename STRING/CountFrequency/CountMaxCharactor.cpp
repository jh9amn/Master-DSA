// count max number of charactor

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s = "leetcode";
    int n = s.length();
    vector<int> arr(26,0);

    for(int i=0; i<n; i++){
        char ch = s[i];
        int ascii = int(ch);
        arr[ascii - 97]++;
    }

    int mx = 0;
    for(int i=0; i<26; i++){
        if(arr[i]>mx)  mx = arr[i];
    }

    for(int i=0; i<26; i++){
        if(arr[i] == mx){
            int ascii = i+97;
            char ch = char(ascii);
            cout<<ch<<" "<<mx<<endl;
        }
    }
}

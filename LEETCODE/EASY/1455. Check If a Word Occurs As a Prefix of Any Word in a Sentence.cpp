#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int n = searchWord.size();

        int wordCnt = 1;
        string currWord = "";
        for(int i=0; i<=s.size(); i++){
            // if space by word or last word in sentence 
            if(s[i] == ' ' || i == s.size()){
                if(currWord.size() >= n){
                    string ss = currWord.substr(0,n);
                    if(ss == searchWord) {
                        return wordCnt;
                    }
                }
                wordCnt++;
                currWord = "";
            }
            else {
                currWord += s[i];
            }
        }
        return -1;
    }
};
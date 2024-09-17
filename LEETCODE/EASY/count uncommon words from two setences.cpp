#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string, int> mp;

        auto countWords = [&] (string &s){
            string z = "";
            int n = s.size();
            for(int i=0; i<n; i++){
                if(i == n-1) {
                    z += s[i];
                    mp[z]++;
                }
                else if(s[i] == ' '){
                    mp[z]++;
                    z = "";
                }
                else {
                    z += s[i];
                }
            }
        };

        countWords(s1);
        countWords(s2);

        vector<string> ans;
        for(auto &[word, count] : mp){
            if(count == 1){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";
        for(int i=0; i<n;){
            int j = i;
            int count = 0;
            while(j < n and word[j] == word[i]){
                count++;
                j++;
                if(count == 9){
                    ans += to_string(9);
                    ans += word[i];
                    count = 0;
                }
            }
            if(count > 0){
                ans += to_string(count);
                ans += word[i]; 
            }

            i = j;
        }
        return ans;
    }
};
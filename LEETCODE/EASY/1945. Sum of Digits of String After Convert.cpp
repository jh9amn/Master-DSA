#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";

        int i=0;
        while(i < s.size()){
            num += to_string(s[i] - 'a' + 1);
            i++;
        }

        int val = 0;
        while(k--){
            int temp = 0;
            for(int j=0; j<num.size(); j++){
                temp += num[j] - '0';
            }
            val = temp;
            num = to_string(val);
        }
        return val;
    }
};
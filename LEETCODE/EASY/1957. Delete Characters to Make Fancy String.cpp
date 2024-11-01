// 1957. Delete Characters to Make Fancy String


#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.size();
        ans += s[0];
        for(int i=1; i<n; i++){
            if(ans.size() < 2 || !(ans[ans.size() - 1] == s[i] && ans[ans.size() - 2] == s[i]))
            ans += s[i];
        }
        return ans;
    }
};
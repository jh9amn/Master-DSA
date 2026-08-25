#include<bits/stdc++.h>
using namespace std;

int main() {}

class Solution {
public:

    /*
    1) insert the p[0] at start or p[1] at last
    2) check which is giving maximum
    3) edge case if p[0] == p[1] 
        NOTE: The formula( n*(n-1))/2 calculates the number of unique pairs you can form from a group of n items.

        ex: text = "aabba"; pattern = "aa"
            cnt = 3
                (3*2)/2 = 3 possible pairs

    */
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();

        long long cnt1 = 0, ans1 = 0;

        string first = pattern[0] + text;
        for(int i=0; i<first.size(); i++) {
            if(first[i] == pattern[0]) cnt1++;
            else if(first[i] == pattern[1]) ans1 += cnt1;
        }
        
        if(pattern[0] == pattern[1]) ans1 = cnt1*(cnt1-1)/2;


        string last = text + pattern[1];
        long long cnt2 = 0, ans2 = 0;
        for(int i=last.size()-1; i >=0 ; i--) {
            if(last[i] == pattern[1]) cnt2++;
            else if(last[i] == pattern[0]) ans2 += cnt2;
        }

        if(pattern[0] == pattern[1]) ans2 = cnt2*(cnt2-1)/2;

        return max(ans1, ans2);
    }
};

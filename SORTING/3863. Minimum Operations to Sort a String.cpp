#include<bits/stdc++.h>
using namespace std;
int main() {}
class Solution {
public:
    /*
    t = sort(s)

    1) if s == t -> return 0

    2) if s == 2 -> return -1
    
    NOTE: ** we can choose any substring for sorting, not the entire string **

    FIRST CASE :)
    3) s[0] == t[0] || s[n-1] == t[n-1] : 
        then remaing can be sorting in one go (1 ---> n-1) or (0 ---> n-2)
        -> return 1

    SECOND CASE :)
    4) sort(1 -> n-1) then sort(0 -> n-2) and viseversa
        -> return 2 
    
    THIRD CASE :)
    5) | maxChar | | | | | | minChar |
    in this case when maxchar at 0th idx and minchar n-1th idx,
    sort(0, n-2) --> 1st opration then max ele comes at idx n-2
    sort(1, n-1) --> 2nd opration then min ele comes at idx 1 and max ele at idx n-1
    sort(0, n-2) --> 3rd opration then min comes at 0th idx and remain all will be sorted
        3 operation so 
            -> return 3 (worst case)

    */
    int minOperations(string s) {
        string t = s;
        sort(begin(t), end(t));
        int n = s.size();

        if(s == t) return 0;
        if(n == 2) return -1;

        // first case
        if(s[0] == t[0] || s[n-1] == t[n-1]) return 1;

        // second case
        string s1 = s;
        sort(begin(s1)+1, end(s1));
        sort(begin(s1), begin(s1) + n-1);

        string s2 = s;
        sort(begin(s2), begin(s2) + n-1);
        sort(begin(s2)+1, end(s2));

        if(s1 == t or s2 == t) return 2;

        // at last third worst case
        return 3;

    }
};

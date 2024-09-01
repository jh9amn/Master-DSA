#include<bits/stdc++.h>
using namespace std;
int main(){}
class Solution {
public:
    bool checkTwoChessboards(string a, string b) {
        int c1 = a[0] - 'a' + 1;
        int v1 = a[1] - '0';

        int r1 = c1 + v1;

        int c2 = b[0] - 'a' + 1;
        int v2 = b[1] - '0';

        int r2 = c2 + v2;

        if(r1 % 2 == 0 and r2 % 2 == 0) return true;
        else if(r1 % 2 == 1 and r2 % 2 == 1) return true;
        return false;
    }
};
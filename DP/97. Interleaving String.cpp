#include<bits/stdc++.h>
using namespace std;
int main(){}


/*
 ### Two pointer approach get failed here 
 str1 = abc
 str2 = adc;
 str3 = adacbc

 str1[i] == str3[k]  i++ k++
 we need next char d but we can only get char b or char a 
 :: hence failed here..


 #### We can go with dp approach 
 i = represennt char of str1
 j = represent char of str2
 k = represent char of str3

 we will pick each and every case like 
 first with str1 pick or not pick 
 then str2 pick and not pick.. 
*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        map<pair<int, pair<int, int>>, bool> dp;

        function<bool(int, int, int)> solve = [&] (int i, int j, int k) -> bool {
            if(k == z) return (i == x && j == y);

            if(dp.count({i,{j,k}})) return dp[{i,{j,k}}];

            bool fromS1 = false;
            bool fromS2 = false;
            if(i < x && s1[i] == s3[k]) {
                fromS1 = solve(i+1, j, k+1);
            }
            if(j < y && s2[j] == s3[k]){
                fromS2 = solve(i, j+1, k+1);
            }
            return dp[{i,{j, k}}] = fromS1 || fromS2;
        };
        return solve(0, 0, 0);
    }
};


/*
### more space optimized
    The index of k = i + j always..
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        map<pair<int,int>, bool> dp;

        function<bool(int, int)> solve = [&] (int i, int j) -> bool {
            int k = i + j;      // k == i + j
            if(k == z) return (i == x && j == y);

            if(dp.count({i, j})) return dp[{i, j}];

            bool fromS1 = false;
            bool fromS2 = false;
            if(i < x && s1[i] == s3[k]) {
                fromS1 = solve(i+1, j);
            }
            if(j < y && s2[j] == s3[k]){
                fromS2 = solve(i, j+1);
            }
            return dp[{i, j}] = fromS1 || fromS2;
        };
        return solve(0, 0);
    }
};

#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    // T.C = O(nlogn) + n      S.C = O(1)
    long long dividePlayers(vector<int>& skill) {
        // sort 
        sort(skill.begin(), skill.end());

        int n = skill.size();

        // use two pointers apporoach to create the valid pairs 
        int i = 0; int j = n-1;
        int checker = 0;

        // check the pairs are valid or not
        while(i <= j){
            if(checker == 0) {
               checker = skill[i] + skill[j];
            }
            else if(checker != skill[i] + skill[j]){
                return -1;
            }
            i++;
            j--;
        }

        // calculate ans...
        long long ans = 0;
        for(int i=0; i<n/2; i++){
            ans += (skill[i] * skill[n-i-1]);
        }
        
        return ans;
    }
};
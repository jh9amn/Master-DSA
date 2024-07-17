#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
         int x = horizontalCut.size();
        int y = verticalCut.size();

        // produce min cost, so cut all max cost first on minimun pieces
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        int i = 0;
        int j = 0;

        int hoizontalPeices = 1;
        int verticalPieces = 1;

        long long ans = 0;

        while(i < x and j < y){
            if(horizontalCut[i] >= verticalCut[j]){
                ans += verticalPieces * horizontalCut[i];
                i++;
                hoizontalPeices++;
            }
            else{
                ans += hoizontalPeices * verticalCut[j];
                j++;
                verticalPieces++;
            }
        }

        while(i < x){
            ans += verticalPieces * horizontalCut[i];
            i++;
            hoizontalPeices++;

        }

        while(j < y){
            ans += hoizontalPeices * verticalCut[j];
            j++;
            verticalPieces++;
        }

        return ans;

    }
};
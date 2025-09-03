#include<bits/stdc++.h>
using namespace std;
int main() {}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int x0 = points[i][0];
            int y0 = points[i][1];

            for(int j=0; j<n; j++){
                if(i == j) continue;

                int x1 = points[j][0];
                int y1 = points[j][1];

                if(x1 >= x0 && y1 <= y0) {
                    int hasPointInside = false;
                    for(int k=0; k<n; k++) {
                        if(k == i || k == j) continue;
                        int x2 = points[k][0];
                        int y2 = points[k][1];

                        // is point inside
                        if(x2 >= x0 && x2 <= x1 && y0 >= y2 && y1 <= y2){
                            hasPointInside = true;
                            break;
                        }
                    }

                    if(!hasPointInside) ans++;
                }
            }
        }
        return ans;
    }
};

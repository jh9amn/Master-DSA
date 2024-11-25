#include<bits/stdc++.h>
using namespace std;
int main(){}

/*
1) visualize this 2D matrix in string form.
2) Like "123405" and our target form is "123450".
3) use graph BFS to find shorted path (min moves) to reach destination


*** if the 0 value idx is this then we can swap it with these adjecents idx
*** we can perform swaps in four direction with these string indexs (find with help of matrix form)
* 0 -> {1,3}
* 1 -> {0,2,4}
* 2 -> {1,5}
* 3 -> {0,4}
* 4 -> {1,3,5}
* 5 -> {4,2}


position  = 6
total posible state = 6 * 5 * 4 * 3 * 2 * 1 = 6!
T. C = O(6!)
S.C = O(6!)
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string start = "";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }
        
        string target = "123450";

        //adjecent idx where O value index can swap in string
        unordered_map<int, vector<int>> mp;

        // dejecent index where zero can swaps
        mp[0] = {1,3};
        mp[1] = {0,2,4};
        mp[2] = {1,5};
        mp[3] = {0,4};
        mp[4] = {1,3,5};
        mp[5] = {4,2};

        queue<pair<string, int>> q;
        q.push({start,0});  // level/moves

        unordered_set<string> st;

        while(!q.empty()){
            int n = q.size();

            // process all path at this current level
            while(n--){        
                int currLevel = q.front().second;
                string currString = q.front().first;

                q.pop();

                if(currString == target) return currLevel;

                int zeroIdx = currString.find('0');     // index of char '0'

                for(auto swapIdx : mp[zeroIdx]){
                    string tempString = currString;
                    swap(tempString[swapIdx], tempString[zeroIdx]);
                    if(!st.count(tempString)){
                        st.insert(tempString);
                        q.push({tempString, currLevel + 1});
                    }
                }
            }
        }

        return -1;
    }
};
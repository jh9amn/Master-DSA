#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    unordered_map<string, int> memo;

    string createKey(int start, int count, int direction) {
        return to_string(start) + "," + to_string(count) + "," +
               to_string(direction);
    }
    int countTeamsHelper(const vector<int>& rating, int start, int count,
                         int direction) {
        if (count == 3) {
            return 1;
        }

        int n = rating.size();

        string key = createKey(start, count, direction);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int totalTeams = 0;

        for (int i = start; i < n; ++i) {
            if (count == 0 ||
                (direction > 0 && rating[start - 1] < rating[i]) ||
                (direction < 0 && rating[start - 1] > rating[i])) {
                totalTeams +=
                    countTeamsHelper(rating, i + 1, count + 1, direction);
            }
        }

        memo[key] = totalTeams;
        return totalTeams;
    }

    int numTeams(vector<int>& rating) {
        int totalTeams = 0;

        for (int i = 0; i < rating.size(); ++i) {
            totalTeams += countTeamsHelper(rating, i + 1, 1, 1);  // Increasing
            totalTeams += countTeamsHelper(rating, i + 1, 1, -1); // Decreasing
        }

        return totalTeams;
    }
};
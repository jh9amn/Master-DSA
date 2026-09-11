
// optimal with analysis
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> num;

        for(int i=1; i<n; i++){
            fact = fact * i;    // n = 4 -> 1*2*3 = 6
            num.push_back(i);
        }

        num.push_back(n);

        // 0 base indexing
        k = k-1;    // 17 = 17-1 = 16
        string ans = "";   

        // O(n) iterations × O(n) erase = O(n²) tc
        // O(n) sc
        while(true) {

            // 1. Find which number/group contains kth permutation
            ans = ans + to_string(num[k/fact]);     // 16/6 = 3(range)

            // 2. Remove that number
            num.erase(begin(num) + k/fact);

            if(num.size() == 0) break;

            // 3. Find position inside the selected group
            k = k % fact;

            // 4. Reduce factorial for next level
            fact = fact / num.size();
        }
        
        return ans;
    }
};

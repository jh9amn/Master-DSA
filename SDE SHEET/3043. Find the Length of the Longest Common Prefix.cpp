class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(auto it :  arr1){
            while(it) {
                st.insert(it);
                it /= 10;
            }
        }

        int maxiLen = 0;
        for(auto it : arr2){
            while(it) {
                if(st.count(it)) {
                    // calculate the length
                    int len = log10(it) + 1;        // to calculate the number len
                    int num = it;
                    maxiLen = max(len, maxiLen);
                    break;
                }
                it /= 10;
            }
        }

        return maxiLen;
    }
};

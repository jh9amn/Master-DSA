class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26] = {0};

        for(auto &it : tasks) {
            arr[it - 'A']++;
        }

        int maxEle = *max_element(arr, arr+26);     // having max freq of ele
        int maxEleCnt = 0;                          // how many have same max freq
        for(auto it: arr){      
            if(maxEle == it){
                maxEleCnt++;
            }
        }

        return max((int)tasks.size(),
           (maxEle - 1) + n * (maxEle - 1) + maxEleCnt);
    }
};

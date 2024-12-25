#include<bits/stdc++.h>
using namespace std;
int main(){}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        auto findLargestValueFromEachLevel = [&](TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()){
                int n = q.size();
                int maxi = INT_MIN;
                while(n--){
                    TreeNode* temp = q.front();
                    q.pop();

                    if(temp != NULL) maxi = max(maxi, temp -> val);
                    if(temp-> left) q.push(temp -> left);
                    if(temp-> right) q.push(temp -> right);
                }
                ans.push_back(maxi);
            }
        };

        if(root == NULL) return {};
        findLargestValueFromEachLevel(root);
        return ans;
        
    }
};
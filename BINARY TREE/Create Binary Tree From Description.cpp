class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;

        for(auto it : descriptions){
            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];

            // isse node nahi bana hai
            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }
            // isse bhi node nahi bana hai
            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(isLeft) {
                mp[parent] -> left = mp[child];
            }
            else{
                mp[parent] -> right = mp[child];
            }

            // store in childSet for find root, because child it[1] never be a root
            childSet.insert(child);
        }

        for(auto it : descriptions){
            // this value is root
            if(!childSet.count(it[0])){
                return mp[it[0]];
            }
        }
        return NULL;
    }
};
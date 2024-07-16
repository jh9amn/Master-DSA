class Solution {
public:
    // Find Common Ancestor for src and dest
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if(root == NULL || root -> val == startValue || root -> val == destValue){
            return root;
        }

        TreeNode* left = findLCA(root -> left, startValue, destValue);
        TreeNode* right = findLCA(root -> right, startValue, destValue);


        if(left == NULL) return right;
        if(right == NULL) return left;
        return root;
    }

    // generating direction for LCA to src and after LCA to dest using backtrack
    bool findDirection(TreeNode* root, int target, string &path){
        if(root == NULL) return false;
        if(root -> val == target) return true;


        path.push_back('L');
        if(findDirection(root -> left, target, path)) return true;
        path.pop_back();        // backtrack

        path.push_back('R');
        if(findDirection(root -> right, target, path)) return true;
        path.pop_back();        // backtrack

        return false;
    }


    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* LCA = findLCA(root, startValue, destValue);

        string lcaToSrc = "";
        string lcaToDest = "";
        string ans = "";

        findDirection(LCA, startValue, lcaToSrc);       // LCA to Src direction is like "UUUU"
        findDirection(LCA, destValue, lcaToDest);

        int n = lcaToSrc.size();
        while(n--){
            ans += "U";
        }

        return ans + lcaToDest;
    }
};
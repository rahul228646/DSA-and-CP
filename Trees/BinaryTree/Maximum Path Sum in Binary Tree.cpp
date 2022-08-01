class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if(!root)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int tentativeAns = max(max(l, r)+root->val, root->val);
        res = max(res,max(l+root->val+r, tentativeAns));
        return tentativeAns;
    }
    int maxPathSum(TreeNode* root) {
        
        int res = INT_MIN;
        // ans will be saved in res
        solve(root, res);
        return res;
    }
};

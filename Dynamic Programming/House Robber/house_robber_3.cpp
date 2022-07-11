class Solution {
public:
    unordered_map<TreeNode*, vector<int>> dp;
    int rob(TreeNode* root, bool canRob = true) {
        if(!root) return 0;
        if(dp.count(root) && dp[root][canRob] != -1) return dp[root][canRob];
        dp[root] = {-1,-1};
        int dontRob = rob(root -> left, true) + rob(root -> right, true);
        int robRoot = canRob ? root -> val + rob(root -> left, false) + rob(root -> right, false) : -1;
        return dp[root][canRob] = max(dontRob, robRoot);
    }
};

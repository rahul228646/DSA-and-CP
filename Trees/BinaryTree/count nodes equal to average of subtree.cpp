https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/submissions/

class Solution {
public:
    
    pair<int, int> solve(TreeNode* root, int &ans) {
        if(!root) {   
            return {0, 0};
        }
        auto [l_sum, l_count] = solve(root->left, ans);
        auto [r_sum, r_count] = solve(root->right, ans);
        int sum = l_sum + r_sum + root->val;
        int n = l_count + r_count + 1;
        int avg = sum/n;
        if(avg == root->val) ans++;
        return {sum, n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        solve(root, ans); 
        return ans;
    }
};

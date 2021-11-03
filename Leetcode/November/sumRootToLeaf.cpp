

https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/
    1
   / \
  2   3 
 / \
4   9
// ans = 124 + 129 + 13      
class Solution {
public:
    long long int sum = 0;
    void solve (TreeNode* root, long long int ans) {
        if(!root) return;
        ans = ans*10+root->val;
        
        if(!root->left && !root->right) {
            sum += ans;
            return;
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return sum;
    }
};

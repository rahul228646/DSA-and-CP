https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/
https://www.youtube.com/watch?v=X0oXMdtUDwo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=54

class NodeVal {
    public : 
    int mn, mx, sum;
    NodeVal(int mn, int mx, int sum) {
        this->mn = mn;
        this->mx = mx;
        this->sum = sum;
    }
    
};

class Solution {
public:
    NodeVal solve(TreeNode* root, int &ans) {
        if(!root) {
            return NodeVal(INT_MAX, INT_MIN, 0); // any node can override this
        }
        auto l = solve(root->left, ans);
        auto r = solve(root->right, ans);
        if(root->val > l.mx && root->val < r.mn) {
            ans = max(ans, l.sum + r.sum + root->val);
            return NodeVal(min(l.mn, root->val), max(r.mx, root->val), l.sum + r.sum + root->val);
   
        }
        else { 
            ans = max(ans,max(l.sum, r.sum));
            return NodeVal(INT_MIN, INT_MAX, max(l.sum, r.sum)); // no node can override this
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

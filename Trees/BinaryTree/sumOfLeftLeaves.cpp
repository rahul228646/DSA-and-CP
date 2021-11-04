
class Solution {
public:
    // int sum = 0;
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if(!root) return 0;
        if(!root->right && !root->left) if(isLeft) return root->val;
        return sumOfLeftLeaves(root->left, true)+sumOfLeftLeaves(root->right, false);
    }
};

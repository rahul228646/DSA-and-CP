class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* val1, TreeNode* val2) {
        if(root == NULL)
            return NULL;

        if((root->val > val1->val && root->val > val2->val)) // val1 and val2 are in left subtree
            return lowestCommonAncestor(root->left ,val1,val2);
    
        if((root->val < val1->val && root->val < val2->val)) // val1 and val2 are in right subtree
            return lowestCommonAncestor(root->right ,val1,val2);
        
        return root; // val1 and val2 are in different subtrees i.e. root is the lowest common ancestor
    
    }
};

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

// for Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p || root == q) return root; // if root is q or q return root
        TreeNode* l = lowestCommonAncestor(root->left, p, q); // look for q or p in left 
        TreeNode* r = lowestCommonAncestor(root->right, p, q); // look for q or p in right 
        if(l && r) return root; // if p and q exist in different subtrees then l and r would be non null and root is the lca
        return l? l:r; // p and q are in the same subtree 
    }
};

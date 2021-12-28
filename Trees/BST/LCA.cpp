class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* val1, TreeNode* val2) {
            if(root == NULL)
        return NULL;

    
    if(root == val1 || root == val2)
        return root;
    
    else if((root->val > val1->val && root->val > val2->val))
         return lowestCommonAncestor(root->left ,val1,val2);
    
    else if((root->val < val1->val && root->val < val2->val))
        return lowestCommonAncestor(root->right ,val1,val2);
    
    else {
        TreeNode * a = lowestCommonAncestor(root->left ,val1,val2);
        TreeNode * b = lowestCommonAncestor(root->right ,val1,val2);
    
    if(a!=NULL && b!=NULL)
        return root;
    else if(a==NULL && b==NULL)
        return NULL;
    else if(a!=NULL && b==NULL)
        return a;
    else
        return b;
    }
    }
};


    bool hasPathSum(Node *root, int sum) {
        if(!root) return false;
        
        if(!root->left && !root->right && sum-root->data == 0 ) return true;
        return hasPathSum (root->left, sum-root->data) || 
               hasPathSum (root->right, sum-root->data);
        
        
    }

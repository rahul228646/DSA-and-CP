
    Node * bToDLL(Node *root)
    {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        Node *left = bToDLL(root->left);
        Node *right = bToDLL(root->right);
        
        Node *temp = left;
        while(left && left->right) {
            left = left->right;
        }
        root->left = left;
        if(left) left->right = root;
        root->right = right;
        if(right) right->left = root;
        
        return (temp) ? temp : root;
    }

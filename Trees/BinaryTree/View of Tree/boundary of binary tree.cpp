    void leftOfRoot(Node *root, vector<int>& ans) {
        if(!root) return;
        if(!root->left && !root->right) return;
        ans.push_back(root->data);
        if(root->left) leftOfRoot(root->left, ans);
        else leftOfRoot(root->right, ans);
    }
    void rightOfRoot(Node *root, vector<int>& ans) {
        if(!root) return ;
        if(!root->left && !root->right) return;
        
        if(root->right) rightOfRoot(root->right, ans);
        else rightOfRoot(root->left, ans);
        ans.push_back(root->data);
    }
    void leaf(Node *root, vector<int>& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    
    vector <int> boundary(Node *root) {
        //Your code here
        if(!root) return {};
        vector<int> ans;
        ans.push_back(root->data);
        leftOfRoot(root->left, ans);
        leaf(root->left, ans);
        leaf(root->right, ans);
        rightOfRoot(root->right, ans);
        return ans;
        
    }
    

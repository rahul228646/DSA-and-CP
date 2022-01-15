https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
1. find lca
2. find path from lca to start
3. find path from lca to end
4. replace L with U in P1 and return P1+P2

class Solution {
public:
    TreeNode* lca (TreeNode* root, int s, int e) {
        if(!root) return root;
        if(root->val == s || root->val == e) return root;
        TreeNode* l = lca(root->left, s, e);
        TreeNode* r = lca(root->right, s, e);
        if(l && r) return root;
        return (l)?l:r;
    }

    bool getPath (TreeNode* root, int s, string &p) {
        if(!root) return false;
        if(root->val == s)return true;
        p+='L';
        bool l = getPath(root->left, s, p);
        if(l) return l;
        p.pop_back();
        p+='R';
        bool r = getPath(root->right, s, p);
        if(r) return r;
        p.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int s, int e) {
        TreeNode* newRoot = lca(root, s, e);
        string p1, p2;
        cout<<newRoot->val<<endl;
        getPath(newRoot, s, p1);
        getPath(newRoot, e, p2);
        for(auto &c : p1) c = 'U';
        return p1 + p2;

    }
};

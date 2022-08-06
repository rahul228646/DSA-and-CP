
// Time : O(N) 
// Space : O(N)
class Solution {
public:
unordered_map<int,bool> mp;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        if(mp[k-root->val])
            return true;
        else mp[root->val]=true;
        
        return findTarget(root->left,k)||findTarget(root->right,k);
        
    }
};

// Time : O(N) 
// Space : O(N)
class Solution {
public:
    vector<int>  v;
    void solve(TreeNode* root) {
        if(!root) return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int i = 0, j = v.size()-1;
        while(i<j) {
            if(v[i] + v[j] == k) return true;
            else if(v[i] + v[j] > k) j--;
            else i++;
        }
        return false;
    }
};


https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int hd = 0;
        unordered_map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, hd});
        int mn = 0, mx = 0;
        while(!q.empty()) {
            unordered_map<int, vector<int>> t;
            int size = q.size();
            while(size--) {
                auto [curr, hd] = q.front();
                q.pop();
                t[hd].push_back(curr->val);
                if(curr->left) {
                     q.push({curr->left, hd-1});
                }
                if(curr->right) {
                    q.push({curr->right, hd+1});
                }
                mn = min(hd, mn);
                mx = max(hd, mx);
            }
            for(auto [key, val] : t) {
                sort(val.begin(), val.end());
                for(auto i : val)
                    mp[key].push_back(i);
            }
            
        }
        vector<vector<int>> ans;
        for(int i = mn; i<=mx; i++) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};

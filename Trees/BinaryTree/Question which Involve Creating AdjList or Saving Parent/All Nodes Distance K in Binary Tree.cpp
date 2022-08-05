https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=31
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/

class Solution {
public:
    void storeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(curr->left) {
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right) {
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_map<TreeNode*,bool> visited;
        storeParent(root, mp);
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({target, 0});
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto [curr, dist] = q.front();
                q.pop();
                if(dist == k) {
                    ans.push_back(curr->val);
                    while(q.size()) {
                        ans.push_back(q.front().first->val);
                        q.pop();
                    }
                    return ans;
                }
        
                visited[curr] = true;
                if(curr->left && visited.find(curr->left) == visited.end()) {
                     q.push({curr->left, dist+1});
                }
                if(curr->right && visited.find(curr->right) == visited.end()) {
                    q.push({curr->right, dist+1});
                }
                if(mp.find(curr) != mp.end() && visited.find(mp[curr]) == visited.end()) {
                    q.push({mp[curr], dist+1});
                }
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> lvl;
        queue<Node *> q;
        q.push(root);
        int size = q.size();
        
        while(!q.empty()) {
            auto curr = q.front();
            lvl.push_back(curr->val);
            size--;
            q.pop();
            for(auto children : curr->children) {
                q.push(children);
            }
            if(size == 0) {
                ans.push_back(lvl);
                size = q.size();
                lvl = {};
            }
        }
        return ans;
    }
};

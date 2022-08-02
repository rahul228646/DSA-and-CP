class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,Node*> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto x = q.front();
                auto node = x.first;
                int hd = x.second;
                q.pop();
                mp[hd] = node;
                if(node->left) {
                    q.push({node->left, hd-1});
                }
                if(node->right) {
                    q.push({node->right, hd+1});
                }
            }
        }
        vector<int> ans;
        for(auto x : mp) {
            ans.push_back(x.second->data);
        }
        return ans;
    }
};

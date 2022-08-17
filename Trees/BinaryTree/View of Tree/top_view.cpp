// https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
// Time : O(n) Space : O(n)
       10(0)
     /        \
  20(-1)      30(1)   ===> 40 20 10 30 100  
 /    \       /    \
40(-2) 60(0) 90(0)  100(2)
         
vector<int> topView(Node *root) {
        //Your code here
        unordered_map<int, int> mp;
        queue<pair<Node*, int>> q;
        int mx = INT_MIN, mn = INT_MAX;
        q.push({root, 0});
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front().first;
                int hd = q.front().second;
                q.pop();
                mx = max(hd, mx);
                mn = min(hd, mn);
                if(mp.find(hd) == mp.end()) mp[hd] = curr->data;
                if(curr->left) q.push({curr->left, hd-1});
                if(curr->right) q.push({curr->right, hd+1});
            }
        }
        vector<int> ans;
        for(int i = mn; i<=mx; i++) {
            ans.push_back(mp[i]);
        }
        return ans;
}

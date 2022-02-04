// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Time : O(N*logK)
// Space : O(N + K)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue <int> pq;
        queue<TreeNode*> q;
        if(!root) return 0;
        q.push(root);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(pq.empty() || pq.size()<k) pq.push(curr->val);
            else if(pq.top() > curr->val){
                pq.pop();
                pq.push(curr->val);
            }
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return pq.top();
    }
};

// Time : O(N+k)
// Space : O(N)
// iterative inordered traversal using stack
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(true) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            k--;
            if(k == 0) return root->val;
            root = root->right;
        }
        return 0;
    }
};



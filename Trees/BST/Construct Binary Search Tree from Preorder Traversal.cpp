https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* solve(vector<int>& pre, int mn, int mx, int &idx) {
        if(idx == pre.size() || pre[idx] > mx || pre[idx] < mn) return nullptr;
        TreeNode* root = new TreeNode(pre[idx++]);
        auto l = solve(pre, mn, root->val, idx);
        auto r = solve(pre, root->val, mx, idx);
        root->left = l;
        root->right = r;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int idx = 0;
        return solve(pre, INT_MIN, INT_MAX, idx);
    }
};

// or

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st; // monotonic decreasing stack
        TreeNode* root = new TreeNode (preorder[0]); 
        st.push(root);
        for(int i = 1; i<preorder.size(); i++) {
            TreeNode* curr = new TreeNode(preorder[i]);
            if(st.size() && preorder[i] < st.top()->val) st.top()->left = curr;
            else {
                TreeNode* temp = nullptr;
                while(st.size() && preorder[i] > st.top()->val) {
                    temp = st.top();
                    st.pop();
                }
                temp->right = curr;
            }
            st.push(curr);
        }
        return root;
    }
};

// root - 8;
// stack - 12
//      8
//     / \
//    5  10
//   / \
//  1   7

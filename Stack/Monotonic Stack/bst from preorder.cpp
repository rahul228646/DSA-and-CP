// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/

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
                while(st.size() && preorder[i] > st.top()->val) { // pop till top element is smaller than curr
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
[8,5,1,7,10,12]
root - 8;

Stack :  {8}    {8 5}  {8 5 1}  {8 7}  {10}       {12}  
Tree  :   8       8       8       8      8         8
                 /       /       /      / \       / \
                5       5       5      5  10     5  10
                       /       / \    / \       / \   \
                      1       1   7  1   7     1   7  12

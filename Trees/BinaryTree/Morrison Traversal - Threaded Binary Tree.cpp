
// Morrison Traversal - Iterative Method for Inorder, Preorder and Postorder
// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/
// https://www.youtube.com/watch?v=oz17ihxBxgU

// Preoder
class Solution {
public:
    TreeNode* getRightMostNode(TreeNode* leftNode, TreeNode* curr) {
        while(leftNode->right && leftNode->right != curr) leftNode = leftNode->right;
        return leftNode;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        auto curr = root;
        while(curr) {
            // cout<<curr->val<<" "<<ans.size()<<endl;
            TreeNode* leftNode = curr->left;
            if(!leftNode) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                auto rightMostNode = getRightMostNode(leftNode, curr);
                if(rightMostNode->right == nullptr) {  //create thread
                    rightMostNode->right = curr;
                    curr = curr->left;
                }
                else {
                    rightMostNode->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                
            }
        }
        return ans;
    }
};

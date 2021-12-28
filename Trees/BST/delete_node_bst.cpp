// https://leetcode.com/problems/delete-node-in-a-bst/discuss/1590789/C%2B%2B-Shortest-Recursive-Solution-or-Detailed-Explanation-with-images
// 1 case : both left and right of the key node are null - just return null;
// 2 case : either left or right of the key node is null - return whichever is not null;
// 3 case : both are not null - replace the key node value with the largest value in the left subtree or smallest value in the right subtree, then delete that node. 
  
// Time : O(h) - h is height of the subtree  
// Space : O(1) 
  
class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) {
            if(!root->right && !root->left) {
                return nullptr;
            }
            else if (!root->left) {
                return root->right;
            }
            else if (!root->right) {
                return root->left;
            }
            else {
                TreeNode* temp = root->right;                        
                while(temp->left != nullptr) temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
            
        }
        if(root->val > key)  root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        
        return root;
    }
};


https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53
class Solution {
    TreeNode* first_wrong;
    TreeNode* prev;
    TreeNode* middle_wrong; 
    TreeNode* second_wrong;
public:
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(root->val < prev->val) {
            if(!first_wrong) {
                first_wrong = prev;
                middle_wrong = root;
            }
            else {
                second_wrong = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(!second_wrong) {
            swap(first_wrong->val, middle_wrong->val);
        }
        else {
            swap(first_wrong->val, second_wrong->val);
        }
    }
};

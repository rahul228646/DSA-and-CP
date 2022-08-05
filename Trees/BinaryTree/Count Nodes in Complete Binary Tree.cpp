// https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33
class Solution {
public:
    int heightL(TreeNode* root) {
        int h = 0;
        while(root){
            root = root->left;
            h++;
        }
        return h;
    }
    int heightR(TreeNode* root) {
        int h = 0;
        while(root){
            root = root->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = heightL(root);
        int rh = heightR(root);
        if(lh==rh) {
            return pow(2, lh) - 1; 
        }
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

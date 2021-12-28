
class Solution {
public:
    TreeNode* helper (vector<int>& nums, int l, int r) {
        if(l>r) return nullptr;
        if(l == r) {
            TreeNode* root = new TreeNode (nums[l]);
            return root;
        }
        int mid = (l+r)/2;
        TreeNode* left = helper(nums, l, mid-1);
        TreeNode* right = helper(nums, mid+1, r);
        TreeNode* root = new TreeNode (nums[mid]);
        root->left = left;
        root->right = right;
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return helper(nums, 0, nums.size()-1);
    }
};

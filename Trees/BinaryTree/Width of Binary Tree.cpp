https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/
https://www.youtube.com/watch?v=R9qiY7OK9JQ

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        long long int res = 1;
        while(!q.empty()) {
            int sz = q.size();
            auto [front, front_idx] = q.front();
            auto [back, back_idx] = q.back();
            res = max(back_idx-front_idx+1, res);
            while(sz--) {
                auto [curr, parent_idx] = q.front();
                q.pop();
                long long int left_idx = 0ll + 2*(parent_idx-front_idx) + 1;
                long long int right_idx = 0ll + 2*(parent_idx-front_idx) + 2;
                if(curr->left) {
                    q.push({curr->left, left_idx});
                }
                if(curr->right) {
                    q.push({curr->right, right_idx});
                }
            }
        }
        return res;
    }
};
 
[1,3,2,5,null,null,9,6,null,7]

           1 (0)                 
       /        \ 
  (1) 3          2 (2)     left_idx = 2*(parent_idx) + 1  right_idx = 2*(parent_idx-front_idx) + 2 // since this can exceeded long long int we use
    /    \       /  \       left_idx = 2*(parent_idx-front_idx) + 1  right_idx = 2*(parent_idx-front_idx) + 2;
(3) 5 (4)  _  (5)_    9 (6)
   / \    / \   /  \   /
  6   _  _   _  _   _  7 
(7)                     (13)

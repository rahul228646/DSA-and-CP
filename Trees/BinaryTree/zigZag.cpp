// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> s1,s2;
        s1.push(root);
        vector<vector<int>> zigZag;
        while(s1.empty() == false ^ s2.empty() == false){ 
            vector<int> temp;
            while(s1.empty() == false){
                temp.push_back(s1.top()->val);
                if(s1.top()->left != NULL)
                      s2.push(s1.top()->left);
                if(s1.top()->right != NULL)
                      s2.push(s1.top()->right);
                  s1.pop();
            }
            if(temp.size())
                zigZag.push_back(temp);
            temp={};
            while(s2.empty() == false){
                temp.push_back(s2.top()->val);
                if(s2.top()->right != NULL)
                    s1.push(s2.top()->right);
                if(s2.top()->left != NULL)
                    s1.push(s2.top()->left);
                s2.pop();
            }
            if(temp.size())
                zigZag.push_back(temp);
        }
        return zigZag;
    }
    
};

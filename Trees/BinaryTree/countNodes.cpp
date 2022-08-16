https://leetcode.com/problems/count-complete-tree-nodes/submissions/
https://leetcode.com/problems/count-complete-tree-nodes/discuss/2058737/C%2B%2B-oror-Binary-Search-Solution

Time : O(h + h*log(2^h))
  
class Solution {
public:
    bool pathToThisNodeExists(TreeNode* root, int possibleNodes, int lvl) {
        bitset<32> bits(possibleNodes-1); // each bit represent a level 
        int i = lvl-1;
        auto temp = root;
        // cout<<possibleNodes<<" ";
        while(temp && i>=0) {
            // cout<<bits[i];
            if(bits[i] == 0) temp = temp->left;
            else temp = temp->right;
            i--;
        }
        // cout<<endl;
        return temp != nullptr;
    }
    int height(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        return 1+height(root->left);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h = height(root);
        // max no. of nodes on a patriculat level in a binary tree is 2^n;
        int noOfNodes = 0; // each level except last in a balanced tree has 2^n nodes
        for(int i = 0; i<h; i++) {
            noOfNodes += pow(2, i);
        }
        int nodesOnLastLevel = 0;
        int lo = 1, hi = pow(2, h), mid = 0;

        while(lo<=hi) {
            mid = (lo+hi)/2;
            if(pathToThisNodeExists(root, mid, h)) {
                nodesOnLastLevel = mid;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return noOfNodes+nodesOnLastLevel;
    }
};

        1
     /     \   
    2       3
   / \     / 
  4   5   6
(0)  (1) (2)
       
possibleNodes    bitset of possibleNodes-1 (right to left)   
2                 01 (1)
3                 10 (2)
4                 11 (3)     
       
take left for 0 and right for 1,  after going for lvl-1 we will reach at the node on the last level, if it exists
  

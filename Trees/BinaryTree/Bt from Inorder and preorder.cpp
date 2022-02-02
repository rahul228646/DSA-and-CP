// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// time : O(N^2) (because we have to search rootIdx)
class Solution {
public:
    TreeNode* solve(vector<int>& pre, vector<int>& in, int inS, int inE, int preS, int preE) {
        if(inS>inE) return nullptr;
        int rootData = pre[preS];
        int rootIdx = -1;
        for(int i = inS; i<=inE; i++) {
            if(rootData == in[i]) {
                rootIdx = i;
                break;
            }
            
        }
        int lInS = inS;
        int lInE = rootIdx-1;
        int lPreS = preS+1;
        int lPreE = preS+(lInE-lInS)+1;
        int rInS = rootIdx+1;
        int rInE = inE;
        int rPreS = lPreE+1;
        int rPreE = preE;
        TreeNode* root = new TreeNode(rootData);
        TreeNode* left = solve(pre, in,  lInS, lInE, lPreS, lPreE);
        TreeNode* right = solve(pre, in, rInS, rInE, rPreS, rPreE);    
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return solve(pre, in, 0, in.size()-1, 0, pre.size()-1);
    }
};

// prerder--> root left right
// inorder--> left root right

// time : O(N) space : O(N)

class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& pre, vector<int>& in, int inS, int inE, int preS, int preE) {
        if(inS>inE) return nullptr;
        int rootData = pre[preS];
        int rootIdx = mp[rootData];
        int lInS = inS;
        int lInE = rootIdx-1;
        int lPreS = preS+1;
        int lPreE = preS+(lInE-lInS)+1;
        int rInS = rootIdx+1;
        int rInE = inE;
        int rPreS = lPreE+1;
        int rPreE = preE;
        TreeNode* root = new TreeNode(rootData);
        TreeNode* left = solve(pre, in,  lInS, lInE, lPreS, lPreE);
        TreeNode* right = solve(pre, in, rInS, rInE, rPreS, rPreE);    
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i = 0; i<in.size(); i++) mp[in[i]] = i;
        return solve(pre, in, 0, in.size()-1, 0, pre.size()-1);
    }
};

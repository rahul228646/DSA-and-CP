// https://practice.geeksforgeeks.org/problems/image-multiplication0627/1
class Solution
{
    public:
    long mod = 1e9+7;
    void helper(Node* root1, Node* root2, long long &mul) {
        if(!root1 || !root2) return ;
         mul += ((root1->data)*(root2->data))%mod;
         helper(root1->left, root2->right, mul);
         helper(root1->right, root2->left, mul);
    }
    long long imgMultiply(Node *root){
        // code here
        if(!root) return 0;
        long long mul = root->data * root->data;
        helper(root->left, root->right, mul);
        return mul%mod;
    }
};

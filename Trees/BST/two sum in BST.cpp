
// Time : O(N) 
// Space : O(N)
class Solution {
public:
unordered_map<int,bool> mp;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        if(mp[k-root->val])
            return true;
        else mp[root->val]=true;
        
        return findTarget(root->left,k)||findTarget(root->right,k);
        
    }
};

// Time : O(N) 
// Space : O(N)
class Solution {
public:
    vector<int>  v;
    void solve(TreeNode* root) {
        if(!root) return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int i = 0, j = v.size()-1;
        while(i<j) {
            if(v[i] + v[j] == k) return true;
            else if(v[i] + v[j] > k) j--;
            else i++;
        }
        return false;
    }
};

// Time : O(N) 
// Space : O(H)
class BST_iterator {
    stack<TreeNode*> st;
    // reverse true = before;
    // reverse false = next;
    bool reverse;
    public : 
    BST_iterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext() {
        return !st.empty();
    }
    int next() {
        auto node = st.top();
        st.pop();
        if(reverse) pushAll(node->left);
        else pushAll(node->right);
        return node->val;
    }
    void pushAll(TreeNode* root) {
        while(root) {
            st.push(root);
            if(reverse) {
               root = root->right;
            }
            else {
               root = root->left;
            }
        }
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BST_iterator l(root, false);
        BST_iterator r(root, true);
        int i = l.next(), j = r.next(); //before
        while(i<j) {
            if(i+j == k) return true;
            else if(i+j >k) {
                j = r.next(); // before
            }
            else {
                i = l.next();
            }
        }
        return false;
    }
};


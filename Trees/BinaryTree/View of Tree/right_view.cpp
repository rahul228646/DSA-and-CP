
// https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
// Time : O(n) Space : O(n)

    vector<int> rightView(Node *root) {

       vector<int> ans;
       if(!root) ans;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()) {
           int n = q.size(); // updating element size at every level;
           while(n--) {
               Node *front = q.front();
               q.pop();
               if(n==0)  // last element of a level;
                   ans.push_back(front->data);
            
               if(front->left) 
                   q.push(front->left);
               if(front->right) 
                   q.push(front->right);
           }
       }
       return ans;
    }

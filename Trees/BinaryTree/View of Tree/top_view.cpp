// https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
// Time : O(n) Space : O(n)
       10(0)
     /        \
  20(-1)      30(1)   ===> 40 20 10 30 100  if hd < l(max) node goes in left (stack) if hd > r(max) node goes in right (vector) , this happens for each level
 /    \       /    \
40(-2) 60(0) 90(0)  100(2)
         
 vector<int> topView(Node *root)
    {

        //Your code here
        queue<pair<Node*, int>> q;
        stack<int> left; // stack because we need reverse order 40 20 instead of 20 40
        vector<int> right, ans;
        int hd = 0, l = 0, r = 0;
        q.push({root, 0});
        while(!q.empty()) {
            Node *front = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(hd<l) {
                left.push(front->data);
                l = hd; 
            }
            else if(hd>r) {
                right.push_back(front->data);
                r = hd;
            }
            if(front->left) {
                q.push({front->left, hd-1});
            }
            if(front->right) {
                q.push({front->right, hd+1});
            }
        }
        while(!left.empty()) {ans.push_back(left.top()), left.pop();}
        ans.push_back(root->data);
        for(auto i : right) {ans.push_back(i);}
        return ans;
        
    }

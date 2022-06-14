
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(!root) return ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()) {
       int sz = q.size();
       bool flag = true;
       while(sz--) {
           auto curr = q.front();
           q.pop();
           if(flag) {
               ans.push_back(curr->data);
               flag = false;
           }
           if(curr->left) {
               q.push(curr->left);
           }
           if(curr->right) {
               q.push(curr->right);
           }
           
       }
   }
   return ans;
}

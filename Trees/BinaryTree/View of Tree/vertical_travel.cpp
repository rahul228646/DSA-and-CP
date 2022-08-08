
// Time : O(n) Space : O(n)
// to maintain order we have to do Bfs or level order traversal
                   (dfs)            (Bfs)
  1                 2                2
 / \                1 4              1 4
2   3. ======>      5 3  ======>     3 5
 \
  4
   \
    5
    
    vector<int> verticalOrder(Node *root)
    {
  
        unordered_map<int, vector<int> > m;
        int hd = 0;
        queue<pair<Node*, int> > q;
        q.push({root, hd});
        int mn=0,mx=0;
        while (q.size()>0) {
            pair<Node*, int> temp = q.front();
            q.pop();
            hd = temp.second;
            Node* node = temp.first;
            m[hd].push_back(node->data);
     
            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
// to avoid the code given below use ordered map
            if(mn>hd)
              mn=hd;
            else if(mx<hd)
              mx=hd;
        }
        vector<int> ans;
        for (int i=mn;i<=mx;i++) {
            vector<int> tmp=m[i];
            for(int j=0;j<tmp.size();j++) {
              ans.push_back(tmp[j]);
            }
        }
        return ans;
    }




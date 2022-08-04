https://www.youtube.com/watch?v=QtdE7QPsWiU&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=21

void dfsStore(vector<int> adj[], vector<int> &vis, int n, int i, stack<int>& st) {
    vis[i] = 1;
    for(auto k : adj[i]) {
        if(!vis[k])
            dfsStore(adj, vis, n, k, st);
    }
    st.push(i);
}


void dfs(vector<int> adj[], vector<int> &vis, int n, int i) {
    vis[i] = 1;
    for(auto k : adj[i]) {
        if(!vis[k])
            dfs(adj, vis, n, k);
    }
}

int kosaraju(vector<int> adj[], int n) {
    vector<int> vis(n, 0);
    stack<int> st;
    // step 1 call dfs and store nodes in stack
    for(int i = 0; i<n; i++) {
        if(vis[i] == 0) {
            dfsStore(adj, vis, n, i, st);
        }
    }

    // step 2 reverse all edges
    vector<int> revAdj[n];
    for(int i = 0; i<n; i++) {
        for(auto j : adj[i]) {
            revAdj[j].push_back(i);
        }
    }
    // step 3 call dfs in the order of stack
    vis = vector<int>(n, 0);
    int ans = 0;
    while(!st.empty()) {
        int x = st.top();
        if(vis[x] == 0) {
            ans++;
            dfs(revAdj, vis, n, x);
        }
        st.pop();

    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    cout<<kosaraju(adj, n);
}

// Topology Sort don't Work When There is a Cycle https://www.youtube.com/watch?v=QaI45-uf6iE
// only for Directed
// time - O(V+E)
// Space - O(V)
// BFS

vector<int> topoSortBFS(int V, vector<int> adj[]) 
	{
	    // code here    
	   // vector<bool> visited(n, false);
	    vector<int> in(V, 0), ans;
	    for(int i = 0; i<V; i++) {
	        for(auto j : adj[i]) {
	            in[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i<V; i++) {
	        if(in[i] == 0) q.push(i);
	    }
	    while(!q.empty()) {
	        int curr = q.front();
	        q.pop();
	        ans.push_back(curr);
	        for(auto i : adj[curr]) {
	            in[i]--;
	            if(in[i] == 0) q.push(i);
	        }
	    }
	    return ans;
	}


// DFS

void dfs(int i,vector<int> adj[],bool visited[], stack <int> &st)
 {
     visited[i] = true;
     for(int j:adj[i])
     {
         if(visited[j] ==  false)
         {  
             dfs(j,adj,visited,st);
         }
     }  
  
     st.push(i);
}

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
//	vector<bool> visited(V,false);
  	stack <int> st;
    vector <int> v;
    bool visited[V];
    for(int i=0 ;i<V;i++)
     visited[i] = false;
    
    for(int i= 0;i<V;i++)
    {
        if(visited[i] == false)
         dfs(i,adj,visited,st);

    }
    while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
    }

    return v;
 }

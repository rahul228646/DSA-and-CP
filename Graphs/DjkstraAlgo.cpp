	
// shortest path from source to all vertices
// Time : O(E log V) Space : O(V)

// Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. 
// It may give correct results for a graph with negative edges 
// but you must allow a vertex can be visited multiple times and that version will lose its fast time complexity. 
// For graphs with negative weight edges and cycles, Bellman–Ford algorithm can be used, we will soon be discussing it as a separate post

typedef pair<int, int> pd;
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        auto cmp = [] (auto a, auto b) {
            return a.second > b.second;
        };
        priority_queue<pd, vector<pd>, decltype(cmp)> pq(cmp);
        bool visited[V] = {false};
        vector<int> ans;
        pq.push({S,0});
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if(visited[curr.first])
                continue;
            visited[curr.first] = true;
            ans.push_back(curr.first);
            for(auto i : adj[curr.first]) {
                if(!visited[i[0]]) {
                    int nei = i[0];
                    int w = curr.second+i[1];
                    pq.push({nei, w});
                }
            }
        }
        return ans;
    }

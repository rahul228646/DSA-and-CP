https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/successful-marathon-0691ec04/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pd;
	
void dijkstra(int s, int n, vector<pair<int, int>> adj[], vector<int>& dist) {
        // Code here
      
    priority_queue<pd, vector<pd>, greater<pd>> pq;
    bool vis[n+1] = {false};
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        auto [weight, curr] = pq.top();
        pq.pop();
        if(vis[curr]) continue;
        vis[curr] = true;
        for(auto [v, d] : adj[curr]) {
            if(!vis[v]) {
                dist[v] = min(dist[v], d+weight);
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {

    int n, m, k, x, start, end;
    cin>>n>>m>>k>>x;
    vector<int> cityWithChocolates(k, 0);
    for(int i = 0; i<k; i++) {
        cin>>cityWithChocolates[i];
    }
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i<m; i++) {
        int u, v, d;
        cin>>u>>v>>d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    cin>>start>>end;
    vector<int> toChocolate(n+1, INT_MAX);
    vector<int> fromChocolate(n+1, INT_MAX);
    dijkstra(start, n, adj, toChocolate);
    dijkstra(end, n, adj, fromChocolate);
    int ans = INT_MAX;
    for(int i = 0; i<k; i++) {
        if(toChocolate[cityWithChocolates[i]] != INT_MAX && fromChocolate[cityWithChocolates[i]] < x) {
            ans = min(ans, toChocolate[cityWithChocolates[i]] + fromChocolate[cityWithChocolates[i]]);
        }
    }
    if(ans != INT_MAX) cout<<ans<<endl;
    else cout<<-1<<endl;
}

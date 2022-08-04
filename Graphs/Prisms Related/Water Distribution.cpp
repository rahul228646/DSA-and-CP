https://www.youtube.com/watch?v=gc6ShDTldb4&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=16

int waterDist(vector<pair<int, int>> adj[], vector<int> wells, int V) {

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<bool> visited(V+1, false);
    for(int i = 0 ; i<wells.size(); i++) {
        pq.push({wells[i], i+1});
    }

    int k = 0, cost = 0;
    while(!pq.empty() && k<V) {
        auto [c, p] = pq.top();
        pq.pop();
        if(!visited[p]) {
            visited[p] = true;
            cost += c;
            k++;
            for(auto [next_p, next_cost] : adj[p]) {
                pq.push({next_cost, next_p});
            }
        }
    }
    return cost;
}
int main() {
    int V, E;
    cin>>V>>E;
    vector<int> wells;
    vector<pair<int, int>> adj[V+1];
    for(int i = 0; i<V; i++) {
        int x;
        cin>>x;
        wells.push_back(x);
    }
    for(int i = 0; i<E; i++) {
        int x, y, c;
        cin>>x>>y>>c;
        adj[x].push_back({y, c});
    }

    cout<<waterDist(adj, wells, V)<<endl;
}


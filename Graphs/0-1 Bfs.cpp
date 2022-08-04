//pseudocode
vector<vector<int>> adj;

vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }
}

// Dijkstra uses a set or priority queue because at every iteration edge with smallest cost is required so an additional time of sorting 
// the edges is involved at each step

// Suppose we have a special weighted graph where each edge has a weight of 0 or 1 , here we can apply dijkstra as above but can we do any better?

// The answer is yes we can use 0-1 BFS which is obtained by combining BFS with Dijkstra
// In BFS we use queue in Dijkstra we use set in 0-1 BFS we use Deque, Deque allows insertion as well deletion from both ends in O(1)

// Since we only have 0 and 1 as weight whenever we encounter an node which is connected by 0 weight edge we 
// push that node at front of deque otherwise we push it at end of deque push nodes in this fashion always results in deque 
// being sorted and we overcome the sorting required at each iteration during Dijkstra, the same technique can be generalized for 
// any di-weighted graph push the node connected with smaller weight edge at front and larger weight at end

https://www.youtube.com/watch?v=sAk4W8q0Rmw&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=23
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;


class Articulation_Point {
    vector<int> parent;
    vector<int> discovery;
    vector<int> low;
    vector<bool> visited;
    vector<bool> articulation_point;
    int time;
    int V;
public :
    Articulation_Point(vector<int> adj[], int V, int &ans) {
        this->V = V;
        parent.resize(V, -1);
        discovery.resize(V, 0);
        low.resize(V, 0);
        visited.resize(V, false);
        articulation_point.resize(V, false);
        time = 0;
        parent[0] = -1; // 0 is source
        dfs(adj, 0);
        for(int i = 0; i<V; i++) {
            if(articulation_point[i]) ans += 1;
        }
    }
    void dfs(vector<int> adj[], int u) {
        discovery[u] = low[u] = time;
        time++;
        int count = 0;
        visited[u] = true;
        for(int v : adj[u]) {
            if(parent[u] == v) {
                continue;
            }
            else if(visited[v]) {
                low[u] = min(low[u], discovery[v]);
            }
            else{
                parent[v] = u;
                count++;
                dfs(adj, v);
                low[u] = min(low[u], low[v]);
                if(parent[u] == -1) { // source vertex
                    if(count>=2) // source vertex connects more than two parts
                        articulation_point[u] = true;
                }
                else{
                    if(parent[u] != -1 && low[v]>= discovery[u]) { // neighbour cannot be visited by other path
                        articulation_point[u] = true;
                    }
                }
            }
        }
    }


};

int main() {
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i = 0; i<E; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    int ans = 0;
    Articulation_Point ap(adj, V, ans);
    cout<<ans<<endl;


//    cout<<articulation_point(adj, V);
}


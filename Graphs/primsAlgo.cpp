
Time: O(E.logV)
Space: O(V)

// “Kruskal’s algorithm” expands the “minimum spanning tree” by adding edges. 
//  Whereas “Prim’s algorithm” expands the “minimum spanning tree” by adding vertices.
	
class Solution {
public:
  
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<bool> visited(n, false);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for(int i = 1; i<n; i++) {
            int val = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]); // calc all cost from vertex 1 and add to queue {cost, vertex1, vertexi}
            pq.push({val, {0, i}});
        }

        visited[0] = true; // mark 1st vertex as visited
        int k = 0, cost = 0;
        
        while(!pq.empty() && k<n-1) {
            auto [val, vertices]= pq.top();
            auto [x, y] = vertices;
            pq.pop();
            if(!visited[y]) { // selecte the ith (which is on top of min heap) and calc. and add other cots of other unvisited vertex from it
                visited[y] = true;
                cost += val;
                k++;
                for(int i = 0; i<n; i++) {
                    if(!visited[i]) {
                        int temp_val = abs(points[i][0] - points[y][0]) + abs(points[i][1] - points[y][1]);
                        pq.push({temp_val, {y, i}});
                    }
                }
            }
        }
        
        return cost;
        
    }
};

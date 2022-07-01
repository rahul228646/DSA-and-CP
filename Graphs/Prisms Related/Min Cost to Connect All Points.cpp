// https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/
Time : O((N-1)*logN) // O(ElogV)
Space : O(N)
  
class Solution {
public:
    using pr = pair<int, pair<int, int>>;
    int prismAlgo(vector<vector<int>>& points, int n) {
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        for(int i = 1; i<n; i++) {   // 0 to all other vertices
            int w = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            pq.push({w, {0, i}});
        }
        int ans = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        int k = 0;
        while(pq.size() || k<n-1) {
            auto [weight, vertices] = pq.top();
            auto [x, y] = vertices;
            pq.pop();
            if(!visited[y]) {
                visited[y] = true;
                ans+=weight;
                k++;
                for(int i = 0; i<n; i++) {
                    if(!visited[i]) {
                        int w = abs(points[i][0] - points[y][0]) + abs(points[i][1] - points[y][1]);
                        pq.push({w, {y, i}});
                    }
                }
            }
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        return prismAlgo(points, points.size());
    }
};

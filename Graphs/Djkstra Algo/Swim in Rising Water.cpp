https://leetcode.com/problems/swim-in-rising-water/submissions/

class Solution {
public:
    typedef pair<int, pair<int, int>>  pr;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({grid[0][0], {0, 0}});
        while(pq.size()) {
            auto [maxWait, coord] = pq.top();
            auto [i, j] = coord;
            if(i == n-1 && j == m-1) return maxWait;
            pq.pop();
            if(visited[i][j]) continue;
            visited[i][j] = 1;
            for(auto [x, y] : dir) {
                int nwi = i+x, nwj = j+y;
                if(nwi<0 || nwj<0 || nwi>=n || nwj>=m || visited[nwi][nwj]) continue;
                pq.push({max(maxWait, grid[nwi][nwj]),{nwi, nwj}});
            }
        }
        return -1;
    }
};

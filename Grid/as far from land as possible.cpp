https://leetcode.com/problems/as-far-from-land-as-possible/submissions/

#define p pair<int, int>
class Solution {
public:
    vector<p> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<p> q;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1) q.push({i, j});
            }
        }
        if(q.size() == n*m)
            return -1;
        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            dist++;
            while(size--) {
                auto [x, y] = q.front();
                q.pop();
                for(auto [i, j] : dir) {
                    if(x+i>=0 && x+i<n && y+j>=0 && y+j<m && grid[x+i][y+j] == 0){
                        q.push({x+i, y+j});
                        grid[x+i][y+j] = 1;
                    }
                }
            }
        }
        return dist-1;
    }
};

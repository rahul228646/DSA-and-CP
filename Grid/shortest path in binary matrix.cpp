// BFS
// Time : O(N*M)
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        grid[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto [i, j] = q.front();
            if(i==n-1 && j == n-1) return grid[i][j]; // first time we reach the end of the matrix is the shortest path (property of BFS)
            q.pop();
            for(auto [dx, dy] : dir) {
                int x = i + dx, y = j+dy;
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y] == 0) {
                    q.push({x, y});
                    grid[x][y] = 1+grid[i][j];
                }
            }
        }
        return -1;
    }
};

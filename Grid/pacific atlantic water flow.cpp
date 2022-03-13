https://leetcode.com/problems/pacific-atlantic-water-flow/

#define p pair<int, int>

class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    void bfs(vector<vector<bool>>& vis, vector<vector<int>>& h, queue<p> &q, int n, int m) {
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int curr_h = h[x][y];
            for(auto [i, j] : dir) {
//               h[x+i][y+j] >= curr_h is done and not h[x+i][y+j] <= curr_h since we are going backward i.e. from ocean to cells
                if(x+i>=0 && x+i<n && y+j>=0 && y+j<m && !vis[x+i][y+j] && h[x+i][y+j] >= curr_h){
                    q.push({x+i, y+j});
                    vis[x+i][y+j] = true;
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        
        vector<vector<bool>>pacificVisited(n,vector<bool>(m,false));
        vector<vector<bool>>atlanticVisited(n,vector<bool>(m,false));
        
        queue<p> q;
        
        for(int i = 0; i<n; i++) {
            if(!pacificVisited[i][0]) {
                q.push({i, 0});
                pacificVisited[i][0] = true;
            }
        }
        
        for(int i = 0; i<m; i++) {
            if(!pacificVisited[0][i]) {
                q.push({0, i});
                pacificVisited[0][i] = true;
            }
        }
        
        bfs(pacificVisited, h, q, n, m);
        
//         for(int i = 0; i<n; i++) {
//             for(int j = 0; j<m; j++) {
//                 cout<<pacificVisited[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        for(int i = 0; i<n; i++) {
            if(!atlanticVisited[i][m-1]) {
                q.push({i, m-1});
                atlanticVisited[i][m-1] = true;
            }
        }
        
        for(int i = 0; i<m; i++) {
            if(!atlanticVisited[n-1][i]) {
                q.push({n-1, i});
                atlanticVisited[n-1][i] = true;
            }
        }
        
       bfs(atlanticVisited, h, q, n, m);
//        cout<<endl; 
//        for(int i = 0; i<n; i++) {
//             for(int j = 0; j<m; j++) {
//                 cout<<atlanticVisited[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        vector<vector<int>> ans;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
   pacific
pa 1 2 2 3 5 a 
ci 3 2 3 4 4 tl
fi 2 4 5 3 1 an
i  6 7 1 4 5 ti
c  5 1 1 2 4 c
   atlantic
   
pacific - 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 0 0 
1 1 0 0 0 
1 0 0 0 0 

atlantic-
0 0 0 0 1 
0 0 0 1 1 
0 0 1 1 1 
1 1 1 1 1 
1 1 1 1 1 



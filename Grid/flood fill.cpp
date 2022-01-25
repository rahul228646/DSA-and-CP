// DFS
class Solution {
public:
    
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};


void solve(vector<vector<int>>& image, int sr, int sc, int newColor, int colorToBeChanged,  vector<vector<bool>>& visited, int n, int m) {
        
        if(sr<0 || sc<0 || sr>=n || sc>=m || visited[sr][sc] || image[sr][sc] != colorToBeChanged) {
            return ;
        }
        
        image[sr][sc] = newColor;
        
        visited[sr][sc] = true;
        for(int i = 0; i<4; i++) {
            int x = dx[i] + sr;
            int y = dy[i] + sc;
            solve(image, x, y, newColor, colorToBeChanged, visited, n, m);
        }
            
    }
        
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size(); 
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        solve(image, sr, sc, newColor, image[sr][sc], visited, n, m);
        return image;
    }
};

//BSF
class Solution {
public:
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr,sc});
        int oldColor =  image[sr][sc];
        vector<vector<int>> ans = image;
        ans[sr][sc] = newColor;
        image[sr][sc] = -1;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(auto k : dir) {
                int x = f.first+k.first;
                int y = f.second+k.second;
                if(x>=0 && y>=0 && x<n && y<m && image[x][y] == oldColor && image[x][y] != -1) {
                    q.push({x, y});
                    ans[x][y] = newColor;
                    image[x][y] = -1;
                }
            }
        }
        return ans;
    }
};

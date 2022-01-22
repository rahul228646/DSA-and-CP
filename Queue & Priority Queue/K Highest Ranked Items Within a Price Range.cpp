// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/
// Time : O(mnlogK)
struct node {
    int dis;
    int p;
    int r;
    int c;
};
// storing least desired cell at top (max. Heap)
struct compare {
    bool operator () (const node &a, const node &b) {
        if(a.dis != b.dis){
            return a.dis < b.dis;
        }else if(a.p != b.p){
            return a.p < b.p;
        }else if(a.r != b.r){
            return a.r < b.r;
        }
        return a.c < b.c;
    }
};


class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& p, vector<int>& s, int k) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<int>> dis (n, vector<int> (m, -1));
        vector<vector<int>> ans;
        
        // bfs 
        queue<pair<int, int>> q;
        q.push({s[0], s[1]});
        dis[s[0]][s[1]] = 0;
        while(!q.empty()) {
            auto front = q.front();
            int i = front.first;
            int j = front.second;
            q.pop();
            for(auto k : dir) {
                int x = k.first;
                int y = k.second;
                if(i+x>=0 && j+y>=0 && i+x<n && j+y<m && dis[i+x][j+y] == -1 && grid[i+x][j+y] != 0) {
                    dis[i+x][j+y] = 1 + dis[i][j];
                    q.push({i+x, j+y});
                }
            }  
        }
        
        priority_queue<node,vector<node>,compare> pq;
    
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] != 0 && grid[i][j] >= p[0] && grid[i][j] <= p[1] && dis[i][j] != -1) {
                    if(cnt != k) {
                        pq.push({dis[i][j], grid[i][j], i, j});
                        cnt++;
                    }
                    else {
                        auto f = pq.top();
                        if(f.dis > dis[i][j]) {
                            pq.pop();
                            pq.push({dis[i][j], grid[i][j], i, j});
                        }
                        else if(f.dis == dis[i][j]) { 
                            if(f.p > grid[i][j]) {
                                pq.pop(); 
                                pq.push({dis[i][j], grid[i][j], i, j});
                            }
                            else if(f.p == grid[i][j]) {
                                if(f.r > i) {
                                    pq.pop(); 
                                    pq.push({dis[i][j], grid[i][j], i, j});
                                } 
                                else if(f.r == i){
                                    if(f.c > j) {
                                        pq.pop();
                                        pq.push({dis[i][j], grid[i][j], i, j});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        

        while(!pq.empty()) {
            auto i = pq.top();
            pq.pop();
            ans.push_back({i.r, i.c});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


https://leetcode.com/problems/rotting-oranges/submissions/

class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto[i, j] = q.front();
                q.pop();
                for(auto [x,y] : dir){
                    if(x+i>=0 && x+i<m && y+j>=0 && y+j<n && grid[i+x][j+y]==1){
                        grid[i+x][j+y]=2;
                        q.push({i+x,j+y});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};

https://leetcode.com/problems/shortest-path-with-alternating-colors/submissions/
class Solution {
public:
    void bfs(int n , vector<int> r[], vector<int> b[], vector<int>& ansR, vector<int>& ansB) {
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}}); // dest, color, dist;
        q.push({0, {1, 0}});
        
        while(!q.empty()) {
            int size = q.size();
           
                auto [v, z] = q.front();
                auto [c, d] = z;
                q.pop();
                if(c) {
                    for(auto k : r[v]) {
                        if(ansR[k] > d+1) {
                            q.push({k, {0, d+1}});
                            ansR[k] = d+1;
                        }
                    }
                }
                else {
                    for(auto k : b[v]) {
                        if(ansB[k] > d+1) {
                            q.push({k, {1, d+1}});
                            ansB[k] = d+1;
                        }
                    }
                }
            
           
        }
        return;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<int> adjR[n], adjB[n];
        for(auto i : red) {
            adjR[i[0]].push_back(i[1]);
        }
        for(auto i : blue) {
            adjB[i[0]].push_back(i[1]);
        }
        vector<int> ansR(n, INT_MAX);
        vector<int> ansB(n, INT_MAX);

        bfs(n, adjR, adjB, ansR, ansB);
        for(int i = 0; i<n; i++) {
            ansR[i] = min(ansR[i], ansB[i]);
            if(ansR[i] == INT_MAX) ansR[i] = -1;
        }
        ansR[0] = 0;
        return ansR;
    }
};

//             0 - 3
// 1 - 4       1 - 1
// 2 - 0       2 - 0 1 3
// 3 - 0       3 - 0 1 3
// 4 - 3 4     4 - 3
    
// 0 - 1  
// 1 - 2   1 - 2
// 2 - 3   2 - 3
// 3 - 4   3 - 1  


// https://leetcode.com/problems/min-cost-to-connect-all-points/submissions
Time : O(N^2 + (N-1)*logN + ElogE) // for krushkals part Time complexity is O((N-1)*logN + N*logN) or O(E*logV + E*logE)
Sace : O(N)

class union_find {
    vector<int> parent;
    vector<int> rank;
    public : 
    union_find(int n) {
        rank.resize(n, 0);
        parent.resize(n, -1);
    }
    int U_F_find(int x) {
        if(parent[x] == -1) return x;
        return parent[x] = U_F_find(parent[x]); 
    }
    void U_F_union(int to, int from) {
        if(rank[to] > rank[from]) {
            parent[from] = to;
        }
        else if(rank[from] > rank[to]) {
            parent[to] = from;
        }
        else {
            parent[from] = to;
            rank[to]+=1;
        }
    }
    bool U_F_cycle(int x, int y) {
        x = U_F_find(x);
        y = U_F_find(y);
        if(x != y) {
             U_F_union(x, y);
            return false;
        }
        return true;
    }
};

class Solution {
public:
    
    using pr = pair<int, pair<int, int>>;
    int kruskalsAlgo(vector<vector<int>>& p, int n) {
        vector<pr> weight_edges;
        for(int i = 0; i<n; i++) { //O(N^2)
            for(int j = i+1; j<n; j++) {
                int w = abs(p[j][0]-p[i][0])+abs(p[j][1]-p[i][1]);
                weight_edges.push_back({w,{i, j}});
            }
        }
        sort(weight_edges.begin(), weight_edges.end()); //O(ElogE) where E = N*(N-1)/2
        int k = 0, ans = 0;
        union_find uf(n);
        for(auto [w, vertices] : weight_edges) {
            auto [x, y] = vertices;
            if(!uf.U_F_cycle(x, y)) {
                k++;
                ans += w;
            }
            if(k==n-1) break;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        return kruskalsAlgo(points, points.size());
    }
};https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/

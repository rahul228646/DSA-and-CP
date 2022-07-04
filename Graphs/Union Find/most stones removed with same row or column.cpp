https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/217790/C%2B%2B-union-find

class union_find {
    vector<int> parent;

    public : 
    union_find(int n) {
        parent.resize(n, -1);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }
    int U_F_find(int x) {
        if(parent[x] == x) return x;
        return U_F_find(parent[x]); 
    }
    void U_F_union(int to, int from) {
        parent[U_F_find(from)] = U_F_find(to); 
    }
  
    vector<int> groups(){ return parent;}
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        union_find uf(n);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) continue;
                 if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                      uf.U_F_union(i, j); 
                }
            }
        }
        auto g = uf.groups();
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(g[i] == i) count++;
        }
    
        return n-count;
    }
};


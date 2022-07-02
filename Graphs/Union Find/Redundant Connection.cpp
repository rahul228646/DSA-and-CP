https://leetcode.com/problems/redundant-connection/
Time : O(N)
  
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        union_find uf(n+1);
        for(auto i : edges) {
            if(uf.U_F_cycle(i[0], i[1])) {
                ans = {i[0], i[1]};
                break;
            }
        }
        return ans;
    }
};


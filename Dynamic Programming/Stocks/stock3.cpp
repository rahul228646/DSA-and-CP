
class Solution {
public:
    vector<vector<vector<int>>> mem;
    int solve(vector<int>& p, int pos, int t, bool bought) {
        if(pos>=p.size() || t == 0) return 0;
        if(mem[bought][t][pos] != -1) return mem[bought][t][pos];
        
        int res = solve(p, pos+1, t, bought);
        if(bought) {
            res = max(res, solve(p, pos+1, t-1, !bought)+p[pos]);
        }
        else {
            res = max(res, solve(p, pos+1, t, !bought)-p[pos]);
        }
        return mem[bought][t][pos] = res;
    }
    int maxProfit(vector<int>& p) {
        // bought transaction position
        mem.resize(2,vector<vector<int>>(3,vector<int>(p.size(),-1)));
        return solve(p, 0, 2, false);
    }
};

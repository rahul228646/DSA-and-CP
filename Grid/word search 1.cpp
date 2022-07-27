// https://leetcode.com/problems/word-search/submissions/
class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<char>> &b, string w, int i, int j, int idx) {
        if(idx == w.size()) return true;
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j] != w[idx]) return false;
        b[i][j] = '0';
        bool ans = false;
        for(auto [x, y] : dir) ans = ans || dfs(b, w, i+x, j+y, idx+1);
        b[i][j] = w[idx]; // backtracking
        return ans;
    }
    bool exist(vector<vector<char>>& board, string w) {
        int m = w.length();
        if(m == 0) return false;
        for(int i = 0; i<board.size(); i++) {
            for(int j = 0; j<board[i].size(); j++) {
                if(w[0] == board[i][j]) {
                    // cout<<i<<" "<<j<<endl;
                    if(dfs(board, w, i, j, 0)) return true;
                }
            }
        }

        return false;
    }
};

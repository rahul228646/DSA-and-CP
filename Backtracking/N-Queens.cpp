https://leetcode.com/problems/n-queens/submissions/
// Time : 
class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int n, int row, int col, vector<string> board) {
        for(int i = col-1; i>=0; i--) {
            if(board[row][i] == 'Q') return false;
        }
        for(int j = col-1, i = row-1; i>=0 && j>=0; i--, j--) {
             if(board[i][j] == 'Q') return false;
        }
        for(int j = col-1, i = row+1; i<n && j>=0; i++, j--) {
             if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(int n, int col, vector<string> &board) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++) {
            if(isSafe(n, row, col, board)) {
                board[row][col] = 'Q';
                solve(n, col+1, board);
                board[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0) return {{""}};
        if(n == 1) return {{"Q"}};
        vector<string> board(n);
        for(int i = 0; i<n; i++) {
             for(int j = 0; j<n; j++) {
                 board[i].push_back('.');
            }
        }
        solve(n, 0, board); 
        return ans;
    }
};


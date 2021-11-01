// any border O cannot be flipped and any O connected with another O in four directions cannot be flipped
// therefore convert all O to _ the call dfs on _ on all four border and dfs will convert them and any _ connected to them to O
// all the _ that remain after the process are converted to X 

class Solution {
public:

    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs (vector<vector<char>>& board, int n, int m, int i, int j) {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != '_') return;
        board[i][j] = 'O';
        for(auto k : dir) {
            dfs(board, n, m, i+k.first, j+k.second);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = '_';
            }
        }
        // top
        for(int i = 0; i<m; i++) {
            if(board[0][i] == '_')
                dfs(board, n, m, 0, i);
        }
        //bottom
        for(int i = 0; i<m; i++) {
            if(board[n-1][i] == '_')
                dfs(board, n, m, n-1, i);
        }
        //left
        for(int i = 0; i<n; i++) {
            if(board[i][0] == '_')
                dfs(board, n, m, i, 0);
        }
        //right
        for(int i = 0; i<n; i++) {
            if(board[i][m-1] == '_')
                dfs(board, n, m, i, m-1);
        }
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == '_')
                    board[i][j] = 'X';
            }
        }
        
    }
};

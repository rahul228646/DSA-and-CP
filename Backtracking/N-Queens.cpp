https://leetcode.com/problems/n-queens/submissions/
// Time : O(N^N * N!) N! as for each 1st col we have N choices for 2nd col we have N-1 choices ...
// N^N as for each choice we have to run isSafe which is N
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

// Time : O(N!) N! as for each 1st col we as N choices for 2nd col we have N-1 choices ...
// isSafe which is O(1)
class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(int n, int row, int col,  vector<bool> &rowCheck, vector<bool> &lowerDiagonalCheck, vector<bool> &upperDiagonalCheck) {
        
       return  !rowCheck[row] && !lowerDiagonalCheck[row+col] && !upperDiagonalCheck[n-1 + col - row];
    }
    
    void solve(int n, int col, vector<string> &board,  vector<bool> &rowCheck, vector<bool> &lowerDiagonalCheck, vector<bool> &upperDiagonalCheck) {
        
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++) {
            if(isSafe(n, row, col, rowCheck, lowerDiagonalCheck, upperDiagonalCheck)) {
                board[row][col] = 'Q';
                
                rowCheck[row] = true;
                lowerDiagonalCheck[row+col] = true;
                upperDiagonalCheck[n-1 + col - row] = true;
                
                solve(n, col+1, board, rowCheck, lowerDiagonalCheck, upperDiagonalCheck);
                board[row][col] = '.';
                
                rowCheck[row] = false;
                lowerDiagonalCheck[row+col] = false;
                upperDiagonalCheck[n-1 + col - row] = false;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0) return {{""}};
        if(n == 1) return {{"Q"}};
        vector<string> board(n);
        vector<bool> rowCheck(n, false);
        vector<bool> lowerDiagonalCheck(2*n+1, false); //row+col
        vector<bool> upperDiagonalCheck(2*n+1, false); //n-1 + col - row
        for(int i = 0; i<n; i++) {
             for(int j = 0; j<n; j++) {
                 board[i].push_back('.');
            }
        }
        solve(n, 0, board, rowCheck, lowerDiagonalCheck, upperDiagonalCheck); 
        return ans;
    }
};

// lower Diagonal row + col

   0 1 2 3 
       
0  0 1 2 3  
1  1 2 3 4
2  2 3 4 5
3  3 4 5 6  

// upper Diagonal n-1 + col - row
       
   0 1 2 3 
       
0  3 4 5 6  
1  2 3 4 5
2  1 2 3 4
3  0 1 2 3  

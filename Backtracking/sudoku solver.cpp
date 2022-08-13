// https://leetcode.com/problems/sudoku-solver/submissions/
// Time : O(9^(9*9)) for every index we can have 9 calls and there are 9*9 indices
class Solution {
public:
        bool solve(vector<vector<char>> &b, vector<vector<int>> &rC, vector<vector<int>> &cC, vector<vector<unordered_map<int, bool>>> &block) {
            
            for(int i = 0; i<9; i++) {
                for(int j = 0; j<9; j++) {
                    if(b[i][j] == '.') {
                        for(int num = 1; num<=9; num++) {
                            if(!rC[i][num] && !cC[j][num] && !block[i/3][j/3][num]) {
                                rC[i][num] = 1;
                                cC[j][num] = 1;
                                block[i/3][j/3][num] = 1;
                                b[i][j] = num+'0';
                                
                                if(solve(b, rC, cC, block)) return true;
                                
                                rC[i][num] = 0;
                                cC[j][num] = 0;
                                block[i/3][j/3][num] = 0;
                                b[i][j] = '.';
                            } 
                        }
                        return false;
                    }
                }
            }

         
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowCheck(9, vector<int>(10, 0)), colCheck(9,  vector<int>(10, 0));
        vector<vector<unordered_map<int, bool>>> block (3, vector<unordered_map<int, bool>>(3, unordered_map<int, bool>()));

        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] != '.') {
                    rowCheck[i][board[i][j]-'0'] = 1;  
                    block[i/3][j/3][board[i][j]-'0'] = 1;
                     colCheck[j][board[i][j]-'0'] = 1;    
                }
            }
        }
        
        solve(board, rowCheck, colCheck, block);
    }
};

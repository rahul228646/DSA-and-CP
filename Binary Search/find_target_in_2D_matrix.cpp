// https://leetcode.com/problems/search-a-2d-matrix-i/
// Time complexity : log(nm)
// each row is sorted and next element of each row is gretaer than the last element of previous row
// 1 2 3 4
// 5 6 7 8

class Solution {
public:
       bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // treat the matrix as an array, just taking care of indices
        // [0..n*m]
        // (row, col) -> row*n + col
        // i -> [i/n][i%n]
        if(matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int e = matrix[mid/n][mid%n];
            if(target < e)
            {
                end = mid - 1;
            }
            else if(target > e)
            {
                start = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/search-a-2d-matrix-ii/
// time is O(m+n)
// each row and column are sorted independentaly
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r = 0, c = m[0].size()-1;
        while(r<m.size() && c>=0) {
            if(m[r][c] == t) return true;
            if(m[r][c] > t) c--;
            else {
                r++;
            }
        }
        return false;
    }
};

// we from the first element of the last column target is smaller than this. it means that target is not in this column, we do c-- else if target is greater than this value. it means that target could be in this column so we do r++;
// repeat this until we find the target;


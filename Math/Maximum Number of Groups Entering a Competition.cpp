// https://leetcode.com/contest/weekly-contest-304/problems/maximum-number-of-groups-entering-a-competition/
class Solution {
public:

     int maximumGroups(vector<int>& grades) {
        return (int)((sqrt(grades.size() * 8 + 1) - 1)/2);
    }
    
};

// groups can be
// a1       -- 1
// a2 a3    -- 2
// a3 a4 a5 -- 3

// 1 + 2 + 3 + 4 + ... == n
//  x*(x+1)/2 == n
// sum of x natural numbers x = no of groups

// x*(x+1) = 10^5
// x2 + x - 200000 = 0 
// x = 446

//  x*(x+1)/2 <= n
// x^2 + x - 2n = 0;
// x = ( -1 + sqrt(1+8*n) ) /2


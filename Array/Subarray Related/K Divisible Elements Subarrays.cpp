// brute force
https://leetcode.com/contest/weekly-contest-291/problems/k-divisible-elements-subarrays/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {

        int len = nums.size();
        unordered_map<vector<int>, int> s;
        for( int i=0; i<len; i++ ){
            for( int j=i; j<len; j++ ){   
                vector<int> temp;
                for( int k=i; k<=j; k++ ) {
                    temp.push_back(nums[i]);
                }
                s[temp] = 1;
            }
        }
        return s.size();
    }
};

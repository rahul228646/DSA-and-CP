// https://leetcode.com/problems/single-number-ii/submissions/
// https://www.youtube.com/watch?v=cOFAmaMBVps

// all set will be multiple of 3 if they are not then that set bit belongs to the unique element
// Time : O(32*N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<32; i++) {
            int sum = 0;
            for(auto j : nums) {
                if((j>>i) & 1) sum++;
            }
            sum %= 3;
            if(sum != 0)
            ans |= (sum<<i);  
        }
        return ans;
    }
};

// Time : O(N)
// watch vedio
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(auto i : nums) {
            one = (one^i) & (~two);
            two = (two^i) & (~one);
        }
        return one;
    }
};



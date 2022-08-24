// https://leetcode.com/problems/product-of-array-except-self/
// Time : O(n) Space : O(1) if we exclude space for ans

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
        }
        
        for(int i=n-1;i>=0;i--)
        {
            res[i]*=fromLast;
            fromLast*=nums[i];
        }
        return res;
    }
};
// [1, 2, 3, 4] -> 1st loop    res : 1 1 2 6       ->. 2nd loop    res : 6 8  12 24  ==> 24 12 8 6
//                       fromBegin : 1 2 6 24                  fromEnd : 4 12 24 24

// or
// Time : O(n) Space : O(1) no extra space is used

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0, prod = 1;
        for(auto i : nums) {
            if(!i) {
                zero++;
                if(zero>1) break;
            }
            else prod*=i;
        }
        if(zero>1) {
            for(auto &i : nums) i = 0;
            return nums;
        }
        else if(zero>0) {
            for(auto &i : nums) {
                if(!i) i = prod;
                else i = 0;;
            }
        }
        else {
            for(auto &i : nums) {
                i = prod/i;
            }
        }
        return nums;
    }
};

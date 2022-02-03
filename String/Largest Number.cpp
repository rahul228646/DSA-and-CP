// https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](auto a, auto b){
            string x = to_string(a);
            string y = to_string(b);
            return x+y > y+x;
        });
        string ans;
        for(auto i : nums) ans += to_string(i);
        if(ans[0] == '0') return "0";
        return ans;
    }
};


https://www.youtube.com/watch?v=1QybAZMCYhA
https://leetcode.com/problems/majority-element-ii/submissions/

class Solution {
public:
    bool greaterthan3(int val, vector<int> arr) {
        int cnt = 0;
        for(auto i : arr) if(i == val) cnt++;
        return cnt>arr.size()/3;
    }
    vector<int> majorityElement(vector<int>& arr) {
        int cnt1 = 0, cnt2 = 0, val1 = 0, val2 = 0; // there can only be three possiblities n%3 == 0, 1, 2 
        for(int i = 0; i<arr.size(); i++) {
            if(arr[i] == val1) {
                cnt1++;
            }
            else if (arr[i] == val2) {
                cnt2++;
            }
            else {
                if(cnt1 == 0) {
                    val1 = arr[i];
                    cnt1 = 1;
                }
                else if(cnt2 == 0) {
                    val2 = arr[i];
                    cnt2 = 1;
                }
                else {
                    cnt1--;
                    cnt2--;
                }
            }
        }
        vector<int> ans;
        if(greaterthan3(val1, arr)) ans.push_back(val1);
        if(val1 != val2 && greaterthan3(val2, arr)) ans.push_back(val2); //val1 != val2 beacuse this 
        // [1, 1, 1, 1, 1]  will give [1, 1] as answer b ut it should be [1]
        return ans;
    }
};



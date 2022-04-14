// https://leetcode.com/problems/find-k-closest-elements/
// Time : O(N-K)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        while(r-l >= k) {
            if(abs(arr[r]-x) >= abs(arr[l]-x)) {
                r--;
            } 
            else {
                l++;
            }
        }
        return vector<int> (begin(arr) + l, begin(arr)+r+1);
    }
};

// Time : O(NlogN)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int minDiff = INT_MAX, minDiffIdx = -1;
        for(int i = 0; i<arr.size(); i++) {
            if(minDiff > abs(arr[i]-x)) {
                minDiff = abs(arr[i]-x);
                minDiffIdx = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[minDiffIdx]);
        k--;
        int i = minDiffIdx-1, j = minDiffIdx+1; 
        while(k && i>=0 && j<arr.size()) {
            if(abs(arr[j]-x) < abs(arr[i]-x)) {
                ans.push_back(arr[j]);
                j++;
            }
            else {
                ans.push_back(arr[i]);
                i--;
            }
            k--;
        }
        while(k && j<arr.size()) {
            ans.push_back(arr[j++]);
            k--;
        }
        while(k && i>=0) {
            ans.push_back(arr[i--]);
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

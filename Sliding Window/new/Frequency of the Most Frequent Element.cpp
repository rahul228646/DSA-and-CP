https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long int sum = 0, ans = 0, i = 0 ;
        for(int j = 0; j<n; j++) {
            sum += arr[j];
            while((j-i+1)*arr[j] - sum > k && i<j) {
                sum -= arr[i++];
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

// 2 Sum
// Time : O(N) Space : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++) mp[arr[i]] = i;
            
        for(int i = 0; i<n; i++) {
            if(mp.find(target-arr[i]) != mp.end() && mp[target-arr[i]] != i) {
                return { min(mp[target-arr[i]], i), max(mp[target-arr[i]], i) };
            }
        }
        return {};
    }
};

// 3 Sum
// Time : O(N^2 + NlogN) Space : O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res; 
        
        for(int i=0; i<n; i++)  {
                int l = i+1;
                int r = n - 1;
                int sum = 0 - nums[i]; 
                while(l<r) 
                {
                    if(nums[l] + nums[r] == sum)  {
                      ans.push_back({arr[i], arr[l], arr[r]});
                      int l_prev = arr[l], r_prev = arr[r];
                      while(l<r && arr[l] == l_prev) l++;
                      while(l<r && arr[r] == r_prev) r--;       
                  }
                    else if(nums[low] + nums[high] < sum)
                        low++;
                    else
                        high--;
                }
          
            }
          while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};

// 4 Sum
// Time : O(N^3 + NLogN) Space : O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                long long int target2 = 0LL + target - (arr[i]+arr[j]);
                int l = j+1, r = n-1;
                while(l<r) {
                    if(target2 == arr[l]+arr[r]) {
                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                        int l_prev = arr[l], r_prev = arr[r];
                        while(l<r && arr[l] == l_prev) l++;
                        while(l<r && arr[r] == r_prev) r--;   
                    }
                    else if (target2 > arr[l]+arr[r]) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
                while(j+1<n && arr[j+1] == arr[j]) j++;
            }
             while(i+1<n && arr[i+1] == arr[i]) i++;
        }
        return ans;
    }
};


// https://leetcode.com/problems/find-the-duplicate-number/solution/

// Consider an array that has n distinct numbers in the range [1,n]. For example: 
// [1,2,3,4,5]. If we pick any one of these 5 numbers and count how many numbers are less than or equal to it, 
// the answer will be equal to that number. So in [1,2,3,4,5], if you pick the number 4, there's exactly 4 numbers that are less than or equal to 
// If you pick 3 there's exactly 3 numbers that are less than or equal to 3, and so on. 
// However, when you have duplicates in the array, this count will exceed the number at some point. For example: in 
// [4,3,4,5,2,4,1] 3 has 3 numbers less than or equal to it. However, the duplicate number will have a count of numbers less than or equal to itself, 
// that is greater than itself (in this example, 4 which is the duplicate, has 6 numbers that are less than or equal to it). Hence, 
// the smallest number that satisfies this property is the duplicate number.
  
class Solution {
public:
    int smallorequal(int mid, vector<int> arr) {
        int count = 0;
        for(auto i : arr) if(i<=mid) count++;
        return count; 
    }
    int findDuplicate(vector<int>& arr) {
        int hi = arr.size(), lo = 1, mid = 0, ans = 0;
        while(lo<=hi) {
            mid = (lo + hi)/2;
            if(smallorequal(mid, arr) > mid){
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1){
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast){
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
    }
};

  

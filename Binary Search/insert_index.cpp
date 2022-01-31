
// https://leetcode.com/problems/search-insert-position/
// https://leetcode.com/problems/search-insert-position/discuss/423166/Binary-Search-101 --- see this

int searchInsert(vector<int>& a, int target) {
   int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
   return idx;
}
// or
int searchInsert(nums, target) {
    int lo = 0, hi = nums.length; // we might need to inseart at the end
    while(lo < hi) { // breaks if lo == hi
        let mid = lo + (hi-lo)/2; // always gives the lower mid
        if (target > nums[mid]) {
            lo = mid + 1 // no way mid is a valid option
        } else {
            hi = mid // it might be possibe to inseart @ mid
        }
    }
    return lo;
};

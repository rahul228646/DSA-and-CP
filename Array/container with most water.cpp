https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
   int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]); // start with widest container
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++; // find the height just greater than the last one from left
        while (height[j] <= h && i < j) j--; // find the height just greater than the last one from right
    }
    return water;
}
};


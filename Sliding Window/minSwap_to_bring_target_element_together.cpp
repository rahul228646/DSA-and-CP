
class Solution {
public:
    int minSwapTogether(vector<int>& arr, int t) {
        
        int n = arr.size(), targetCount = 0, maxTargetCount = 0;
        
        for(auto i : arr) if(i == t) targetCount++;
        
        int windowSize = targetCount, windowTargetCount = 0;
        
        for(int i = 0; i<windowSize; i++) if(arr[i] == t) windowTargetCount++;
        
        int i = 0, j = windowSize;
        
        maxTargetCount =  windowTargetCount;
        while(j<n-1) {
            if(arr[i] == t) windowTargetCount--;
            if(arr[j] == t) windowTargetCount++;
            maxTargetCount = max(windowTargetCount, maxTargetCount);
            i++;
            j++;
        }
        
        return targetCount - maxTargetCount;
    } 
};

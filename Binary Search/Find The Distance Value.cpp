class Solution {
public:
    int binarySearch(vector<int>& arr2, int target, int d){
        int lo = 0, hi = arr2.size()-1, mid= 0;
        while(lo<=hi) {
            mid = (lo+hi)/2;
            if(abs(arr2[mid]-target) <= d) return 1; // trying to find a value that will make target invalid i.e abs(arr2[mid]-target) <= d
            else if(arr2[mid]>target) hi = mid-1;
            else lo = mid+1;
        }
        return 0;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end()); 
        int invalidAns = 0;
        for(auto i : arr1) {
            if(binarySearch(arr2, i, d)) invalidAns++;
        }
        return arr1.size()-invalidAns;
    }
};

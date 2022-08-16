// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution {
public:
    int binarySearch(vector<long long> prefix, int k, int n) {
        int lo = 0, hi = n-1, mid = 0;
        while(lo<=hi) {
            mid = (lo+hi)/2;
            if(prefix[mid] <= k) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        vector<long long> prefix;
        for(auto i : chalk) {
            sum += i;
            prefix.push_back(sum);
        }
        k = k % sum;
        return binarySearch(prefix, k, n);
    }
};

chalk = [3,4,1,2], k = 25
  
prefix = 3 7 8 10 ; k % sum = 5 

//     or
    
class Solution {
public:
      int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(auto i : chalk) {
            sum += i;
        }
        k = k%sum;
        int i = -1;
        do {
            i++;
            i = i%n;
            k -= chalk[i];
            // cout<<i<<" "<<k<<endl;
        }
        while (k>=0);
        return i;
    }
};



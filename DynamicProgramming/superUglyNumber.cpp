// Time : O(n*k) Space : O(n+k)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> dp (n, 0), pointers(m, 0);
	    dp[0] = 1;
	    for(int i = 1; i<n; i++) {
            int mn = INT_MAX;
            for(int j = 0; j<m; j++) {
                mn = min(primes[j]*dp[pointers[j]], mn);
            }
            dp[i] = mn;
            for(int j = 0; j<m; j++) {
                if(primes[j]*dp[pointers[j]] == mn) {
                    pointers[j]++;
                }
            }
	        
	    }
	    return dp[n-1];
    }
};

// Time : O(n*logk) Space : O(n+k)

class Solution {
public:
    typedef pair<int, pair<int, int>> pr;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<long long> dp (n, 0);
        
        auto compare = [] (pr a, pr b) {
            if(a.first > b.first) return true;
            else return false;
        };
        priority_queue<pr, vector<pr>, decltype(compare) > pq(compare);
	    dp[0] = 1;
        
        for(int i = 0; i<m; i++) {
            pr p;
            p.first = primes[i]; // value
            p.second.first = 0; // pointer
            p.second.second = primes[i]; // prime no
            pq.push(p);
        }
        
	    for(int i = 1; i<n; i++) {
            pr p = pq.top();
            pq.pop();
            if(dp[i-1] != p.first) {
                dp[i] = p.first;
            }
            else i--;
            p.second.first++;
            p.first = p.second.second * dp[p.second.first];
            pq.push(p);
        }

	        
	    return dp[n-1];
    }
};

class Solution {
public:
    int maximumGroups(vector<int>& g) {
        sort(g.begin(), g.end());
        int cnt1 = 1, cnt2 = 0, sum1 = g[0], sum2 = 0, ans = 1;
        for(int i = 1; i<g.size(); i++) {
            if(cnt2<ans) {
                sum2 += g[i];
                cnt2++;
            }
            else if(cnt2 == ans) {
                sum2 += g[i];
                cnt2++;
                sum1 = sum2;
                cnt1 = cnt2;
                cnt2 = 0;
                sum2 = 0;
                ans++;
            }
            // cout<<sum1<<"-"<<cnt1<<"   "<<sum2<<"-"<<cnt2<<endl;
        }
        if(sum2<=sum1 || cnt2<=cnt1) return ans;
        return ans+1;
    }
};


// https://leetcode.com/contest/weekly-contest-304/problems/maximum-number-of-groups-entering-a-competition/
class Solution {
public:

     int maximumGroups(vector<int>& grades) {
        return (int)((sqrt(grades.size() * 8 + 1) - 1)/2);
    }
    
};

// groups can be
// a1       -- 1
// a2 a3    -- 2
// a3 a4 a5 -- 3

// 1 + 2 + 3 + 4 + ... == n
//  x*(x+1)/2 == n
// sum of x natural numbers x = no of groups

// x*(x+1) = 10^5
// x2 + x - 200000 = 0 
// x = 446

//  x*(x+1)/2 <= n
// x^2 + x - 2n = 0;
// x = ( -1 + sqrt(1+8*n) ) /2


https://leetcode.com/problems/jump-game-vii/

    bool solve (string s, int minJump, int maxJump, int curr, int n) {
        if(curr == n-1) return true;
        bool ans = false;
        for(int i = curr+minJump; i<=curr+maxJump; i++) {
            if(i<n && s[i]=='0')
            ans = ans || solve(s, minJump, maxJump, i, n);
        }
        return ans;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.length()-1]=='1') return false;
        return solve(s, minJump, maxJump, 0, s.length());
    }


// Time : O(N) Space : O(N)
    bool canReach(string s, int minJump, int maxJump) {
        int cnt = 0;
        vector<bool> dp(s.size());
        dp[0] = true;
        for (int i = minJump; i < s.size(); ++i) {
            cnt += dp[i - minJump];
            if (i - maxJump > 0)
                cnt -= dp[i - maxJump - 1];
            dp[i] = s[i] == '0' && cnt;
        }
        return dp.back();
    }  


// https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution
// Time : O(n) Space : O(n)
    int solve (vector<int> p, int start, int k) {
        if(p.size()==1) return p[0];
        start = (start + k) % p.size();
        p.erase(p.begin()+start);
        return solve(p, start, k);
    }
    int safePos(int n, int k) {
        vector<int> p(n, 0);
        for(int i = 0; i<n; i++) p[i] = i+1;
        return solve (p, 0, k-1);
    }

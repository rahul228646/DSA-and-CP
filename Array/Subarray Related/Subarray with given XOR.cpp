https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), count = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int x = 0;
    for(int i = 0; i<n; i++) {
        x = A[i]^x;
        if(mp.find(x^B) != mp.end()) {
            count += mp[x^B];
        }
        mp[x]++;
    }
    return count;
}

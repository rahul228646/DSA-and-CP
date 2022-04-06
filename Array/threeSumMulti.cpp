// https://leetcode.com/problems/3sum-with-multiplicity/submissions/
// https://leetcode.com/problems/3sum-with-multiplicity/discuss/181131/C%2B%2BJavaPython-O(N-%2B-101-*-101)

class Solution {
public:
        int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long> c;
        for (int a : A) c[a]++;
        long res = 0;
        for (auto it : c)
            for (auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6; // nCk = n!/(n-k)!*k!   k = 3 , n = count
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k]; // nCk = n!/(n-k)!*k!  k = 2, n = count
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        return res % int(1e9 + 7);
    }
};


// for anyone who is thinking why it is required to check (i < j && j < k) in case 3. here is a simple example to help understand.
// suppose the input is {1,2,3} and target is 6.
// so we are going to have the following combination

// 1.{1,2,3} {i=1,j=2,k=3}
// 2.{1,3,2} {i=1,j=3,k=2}
// 3.{2,1,3} {i=2,j=1,k=3}
// 4.{2,3,1} {i=2,j=3,k=1}
// 5.{3,1,2} {i=3,j=1,k=2}
// 6.{3,2,1} {i=3,j=2,k=1}

// the input must be one and only one of these combinations

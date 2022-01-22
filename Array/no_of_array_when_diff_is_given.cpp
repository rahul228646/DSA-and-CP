    
// https://leetcode.com/problems/count-the-hidden-sequences/

int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long a = 0, ma = 0, mi = 0;
        for (int d: diff) {
            a += d;
            ma = max(ma, a);
            mi = min(mi, a);
        }
        return max(0L, (upper - lower) - (ma - mi) + 1);
}


Assume diff -> [3, -4, 5, 1, -2]
Let's say we start with some 'X' as the starting element.
According to diff; arr[1] will be X + 3; { arr[1] - arr[0] = 3 => arr[1] - X = 3 => arr[1] = X + 3 }.
arr[2] will be X - 1; { arr[2] - arr[1] = -4 => arr[2] - X - 3 = -4 => arr[2] = X - 1 };
Similarly, arr[3] will be X + 4, and so on.

so arr {i.e. hidden sequence} will be [X, X + 3, X - 1, X + 4, X + 5, X + 3];
Now, you observe here, if choose some X, it can be some maximum X + 5 & some minimum X - 1;
Knowing these; you can easily loop over and count for all possible X's and see if X + 5 <= upper & X - 1 >= lower.

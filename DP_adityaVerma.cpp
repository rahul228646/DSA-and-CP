#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;

//1 2 3 4 5 6
//6 = 2->4 = 6
//4 = 2
//2 = 0
//5 = 1->3 = 4
//3 = 1
//1 = 0
//0 0 0+1 0+2 0+1+3 0+2+4 0+1+3+5
//
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




int minCostClimbingStairs(vector<int>& cost) {
   vector<int> minCost (cost.size()+1, 0);
   for (int i = 2; i < minCost.size(); ++i)
       minCost[i] = min(minCost[i-1] + cost[i-1], minCost[i-2] + cost[i-2]);
   return minCost[minCost.size()-1];
}

int countVowelStrings(int n) {
   int sum = 0;
   vector<int> ans(1);
   if(n == 1) return 1;
   int j = 0;
   while(j!=n) {
       sum = 0;
       for (int i = 1; i < 5; ++i) {
           sum += ans[i-1];
           ans[i] += sum;
       }
       j++;
   }

//    for (int i = 0; i < 5; ++i) {
//        sum += ans[i];
//    }
   return sum;
}

//1043. Partition Array for Maximum Sum
//    1 15 7 9 2 5 10  (k = 3)
//    15 15 15 9 9 9 10
//    15 15 15 9 10 10 10

//    1 4 1 5 7 3 6 1 9 9 3  (k = 4)
//    4 7 7 7 7 9 9 9 9 9 9
//    4 7 7 7 7 9 9 9 9 9 9
int maxSumAfterPartitioning(vector<int>& arr, int k) {
   vector<int> dp(arr.size(), 0);
   int sum = 0;
   for (int i = 0; i <arr.size(); ++i) {
       if (i<=arr.size()-k) {
           int maximum = *max_element(arr.begin() + i, arr.begin() + i + k);
           for (int j = i; j < i + k; ++j) {
               dp[i] = max(dp[i],maximum);
           }
       }
       dp[i] = arr[i];
   }
   accumulate(dp.begin(), dp.end(), sum);
   return sum;
}

int mctFromLeafValues(vector<int>& arr) {
   sort(arr.begin(), arr.end());
   int sum  = 0;
   for (int i = 1; i < arr.size(); ++i) {
       sum += (arr[i-1]*arr[i]);
   }
   return sum;
}


// standard Knapsack 0 1 bounded (no multiple occurances)
// identification : value , weight, capacity
class knapsack {
   vector<vector<int>> dp;
   public:
   int solveMem (vector<int> weight, vector<int> val, int cap, int n) {
       if(n <= 0 || cap <=0)
           return 0;
       if(dp[n][cap] != 1) {
           return dp[n][cap];
       }
       if(weight[n-1] <= cap) {
           return dp[n][cap] = max(val[n-1] + solveMem(weight, val, cap-weight[n-1], n-1),
                                   solveMem(weight, val, cap, n-1));
       }
       else {
           return  dp[n][cap] = solveMem(weight, val, cap, n-1);
       }
   }
   int mem(vector<int> weight, vector<int> val, int cap, int n) {
       dp = vector<vector<int>> (n+1, vector<int>(cap+1, -1));
       return solveMem(weight, val, cap, n);
   }

   int solveDp (vector<int> weight, vector<int> val, int cap, int n) {
       dp = vector<vector<int>> (n+1, vector<int>(cap+1, 0));
   // initialise 1st row and 1st column by zero
       for (int i = 1; i < dp.size(); ++i) {
           for (int j = 1; j < dp[i].size(); ++j) {
               if(weight[i-1]<=j) {
                   dp[i][j] = max(val[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
               }
               else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][cap];
   }
};

// problems bases on knapsack
// subset sum, equal sum, count no of subset, minimum subset sum, target sum

// subset sum - given an array return true if there is a subset in the array with its sum equal to the given array
class subsetSum {
public:
   static bool solve (vector<int> arr, int sum, int n) {
       vector<vector<bool>> dp (n+1, vector<bool>(sum+1));
       // initialise 0,0 with true, first row with false and first column with false
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i == 0 && j ==0) dp[i][j] = true;
               else if(i == 0) dp[i][j] = false;
               else if(j == 0) dp[i][j] = true;
           }
       }

       for (int i = 1; i < dp.size(); ++i) {
           for (int j = 1; j < dp[i].size(); ++j) {
               if(arr[i-1]<=j) {
                   dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
               }
               else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][sum];
   }

   int countSubsetSum (vector<int> arr, int sum, int n) {
       vector<vector<int>> dp (n+1, vector<int>(sum+1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i == 0 && j ==0) dp[i][j] = 1;
               else if(i == 0) dp[i][j] = 0;
               else if(j == 0) dp[i][j] = 1;
           }
       }

       for (int i = 1; i < dp.size(); ++i) {
           for (int j = 1; j < dp[i].size(); ++j) {
               if(arr[i-1]<=j) {
                   dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]);
               }
               else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][sum];
   }
};

// equal sum partiotion
class equalSum {
public:
   bool solve (vector<int> arr, int n) {
       int sum = 0;
       for(auto i : arr) sum += i;
       // equal sum partition can only be made if sum is even
       if(sum % 2 != 0) return false;

       // if a partition of sum/2 exists then automatically the other partition will also be sum/2
       subsetSum s;
       return s.solve(arr, sum/2, n);
   }
};

//minimum subset sum difference s1-s2 = min
// wkt s1+s2 = sum ;  => sum - 2*s2 = min ;
// we have to find all subsets of s2 and then see which is min
class subsetSumDiff {
   int solve(vector<int> arr, int n) {
       int sum = 0;
       for(auto i : arr) sum += i;
       if(sum % 2 != 0) return false;

       vector<vector<bool>> dp (n+1, vector<bool>(sum+1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i == 0 && j ==0) dp[i][j] = true;
               else if(i == 0) dp[i][j] = false;
               else if(j == 0) dp[i][j] = true;
           }
       }
       for (int i = 1; i < dp.size(); ++i) {
           for (int j = 1; j < dp[i].size(); ++j) {
               if(arr[i-1]<=j) {
                   dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
               }
               else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       // we will traverse the last row till sum/2
       int ans = INT_MAX;
       for (int i = 0; i <=sum/2; ++i) {
           // cout<<dp[n][i]<<endl;
           if(dp[n][i])
               ans = min(sum - 2*i, ans);
       }
       return ans;
   }
};


// knapsack target sum
class targetSum {
public:
   void subSetSum (vector<vector<int> > &dp, vector<int> nums) {
       for (int i = 1; i < dp.size(); ++i) {
           for (int j = 1; j < dp[i].size(); ++j) {
               if(nums[i-1]<=j) {
                   dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
               }
               else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
   }
   int findTargetSumWays(vector<int>& nums, int target) {
       int range= 0;
       int zeroCount = 0;
       vector<int> a;
       for(auto &i : nums) {
           if(i == 0) zeroCount++;
           else
               a.push_back(i);
           range+=i;
       };
       range = range+target;
       if(range % 2 != 0){
           return 0;
       }
       range /= 2;
       vector<vector<int>> dp (a.size()+1, vector<int> (range+1, 0));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i == 0 && j ==0) dp[i][j] = 1;
               else if(i == 0) dp[i][j] = 0;
               else if(j == 0) dp[i][j] = 1;
           }
       }
       subSetSum(dp, a);
       return dp[a.size()][range]*pow(2, zeroCount);
   }
};


class unBoundedKnapsack {
   vector<vector<int>> dp;
public:
   int solveDp (vector<int> weight, vector<int> val, int cap, int n) {
       dp = vector<vector<int>> (n+1, vector<int>(cap+1, 0));
       // initialise 1st row and 1st column by zero
       for (int i = 1; i < dp.size(); ++i) {
           for (int j = 1; j < dp[i].size(); ++j) {
               if(weight[i-1]<=j) {
                   dp[i][j] = max(val[i-1] + dp[i][j-weight[i-1]], dp[i-1][j]);
               }
               else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][cap];
   }
};

// unbounded knapsack
// coin change ways
class coinChangeWays {
public:
   int change(int amount, vector<int>& coins) {
       vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1));
       for (int i = 0; i <dp.size(); ++i) {
           for (int j = 0; j <dp[i].size(); ++j) {
               if(i==0 && j==0)
                   dp[i][j] = 1;
               else if(i == 0)
                   dp[i][j] = 0;
               else if(j == 0)
                   dp[i][j] = 1;
           }
       }

       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j<dp[i].size(); ++j) {
               if(coins[i-1] <= j)
                   dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
               else
                   dp[i][j] = dp[i-1][j];

           }
       }

       return dp[coins.size()][amount];
   }
};


// unbounded knapsack
// coin change min coins to make the sum
class coinMin {
public:
   int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1));
       for (int i = 0; i <dp.size(); ++i) {
           for (int j = 0; j <dp[i].size(); ++j) {
               if(i==0 && j==0)
                   dp[i][j] = INT_MAX-1;
               // -1 because we will be adding 1 later in the dp matrix
               else if(i == 0)
                   dp[i][j] = INT_MAX-1;
               else if(j == 0)
                   dp[i][j] = 0;
               else if (i == 1 && j != 0) {
                   if(j%coins[0] == 0) dp[i][j] = j/coins[0];
                   else
                       dp[i][j] = INT_MAX-1;
               }
           }
       }

       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j<dp[i].size(); ++j) {
               if(coins[i-1] <= j)
                   dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
               else
                   dp[i][j] = dp[i-1][j];

           }
       }

       return dp[coins.size()][amount];
   }
};
//---------------------------------------------------------------------------------------------------------------------


// longest common subsequence
class lcsMemo {
public:

   vector<vector<int>> dp;
   int longestCommonSubsequenceHelper(string text1, string text2, int size1, int size2) {
       if(size1 == 0 || size2 == 0)
           return 0;
       if(dp[size1][size2] != -1)
           return dp[size1][size2];

       if(text1[size1-1] == text2[size2-1])
           return dp[size1][size2] = (1+ longestCommonSubsequenceHelper(text1, text2, size1-1, size2-1));
       else {
           return dp[size1][size2] =
                   max(longestCommonSubsequenceHelper(text1, text2, size1, size2-1),
                      longestCommonSubsequenceHelper(text1, text2, size1-1, size2));
       }

   }
   int longestCommonSubsequence(string text1, string text2) {
       dp =  vector<vector<int>> (text1.length()+1, vector<int>(text1.length()+1, -1));
       return longestCommonSubsequenceHelper(text1, text2, text1.length(), text2.length());
   }
};

class lcsDp {
public:

   int longestCommonSubsequence(string text1, string text2) {
       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       return dp[size1][size2];
   }
};

// longest repeating subsequence
class lrs {
public:
   int longestRepaetingSubsequenceHelper(string text1, string text2) {
       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1] && i != j) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       return dp[size1][size2];
   }
   int longestRepaetingSubsequence(string text1) {return longestRepaetingSubsequenceHelper(text1, text1);}
};


// longest common substring
class lcsubStrDp {
public:

   int longestCommonSubstr(string text1, string text2) {
       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       int result = 0;
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
                   result = max(dp[i][j], result);
               }
               else {
                   dp[i][j] = 0;

               }
           }
       }
       return result;
   }
};

// print lowest common subsequence
// make dp table to understand or watch AV video 23
class printLcsDp {
public:

   string PrintlongestCommonSubsequence(string text1, string text2) {
       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       string s;
       int i = size1, j = size2;
       while (i>0 && j>0) {
           if(text1[i-1] == text2[j-1]) {
               s.push_back(text1[i-1]);
               i--;
               j--;
           }
           else {
               if(dp[i-1] > dp[j-1]) {
                   i--;
               }
               else {
                   j--;
               }
           }
       }
       reverse(s.begin(), s.end());
       return s;
   }
};

// shortest common subsequence (scs)
class commomSuperSsc {
public:

   int shortestCommonSuperSec(string text1, string text2) {
       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = 0;

               }
           }
       }
       return size1+size2-dp[size1][size2];
   }
};


// shortest common subsequence (scs)
class printScs {
public:

   string printShotestCommonSuperSec(string text1, string text2) {
       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       string s;
       int i = size1, j = size2;
       while (i>0 && j>0) {
           if(text1[i-1] == text2[j-1]) {
               s.push_back(text1[i-1]);
               i--;
               j--;
           }
           else {
               if(dp[i-1] > dp[j-1]) {
                   s.push_back(text1[i-1]);
                   i--;
               }
               else {
                   s.push_back(text2[j-1]);
                   j--;
               }
           }
       }

       while (i>0) {
           s.push_back(text1[i-1]);
           i--;
       }

       while (j>0) {
           s.push_back(text2[j-1]);
           j--;
       }
       reverse(s.begin(), s.end());
       return s;
   }
};



//   heap ----> pea
// 2del \      /  1ins
//        ea
class MinInsertionDeletion {
public:

   pair<int, int> longestCommonSubsequence(string text1, string text2) {
       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       pair<int, int> delIns (size1-dp[size1][size2], size2-dp[size1][size2]);
       return delIns;
   }
};

// edit distance

class editDistance {
public:
   int solve(string s, string t) {
       // Code here
       int l1 = s.length();
       int l2 = t.length();
       int dp[l1+1][l2+1];
       for(int i = 0; i<=l1; i++) {
           for(int j = 0; j<=l2; j++) {
               if(i == 0 && j == 0) {
                   dp[i][j] = 0;
               }
               else if(i == 0) {
                   dp[i][j] = j;
               }
               else if(j == 0) {
                   dp[i][j] = i;
               }
           }
       }

       for(int i = 1; i<=l1; i++) {
           for(int j = 1; j<=l2; j++) {
               if(s[i-1] == t[j-1]) {
                   dp[i][j] = dp[i-1][j-1];
               }
               else {
                   dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
               }
           }
       }
       return dp[l1][l2];

   }
};



// Longest Palindromic subSequence (lps) (lcs--->lps)
// lps
//abc
//bca
class lpsDp {
public:
   int longestPalindromicSubsequenceHelper(string text1, string text2) {

       int size1 = text1.length();
       int size2 = text2.length();
       vector<vector<int>> dp (size1+1, vector<int>(size2+1, -1));
       for (int i = 0; i < dp.size(); ++i) {
           for (int j = 0; j < dp[i].size(); ++j) {
               if(i==0 || j == 0)
                   dp[i][j] = 0;
           }
       }
       for (int i = 1; i <dp.size(); ++i) {
           for (int j = 1; j <dp[i].size(); ++j) {
               if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
               else {
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

               }
           }
       }
       return dp[size1][size2];
   }
   int longestPalindromicSubsequence(string a) {
       string s = a;
       reverse(a.begin(), a.end());
       return longestPalindromicSubsequenceHelper(s, a);
   }
};



// Matrix Chain Multiplication
class McmMatrixMulMinCost {
   vector<vector<int>> dp;
public:
   int solve (vector<int> arr, int i, int j) {
       if(i>=j)
           return 0;
       if(dp[i][j] != -1) //optimization
           return dp[i][j];
       int ans = INT_MAX;
       for (int k = i; k <=j-1; ++k) {
//            int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
//            ans = max(ans, temp);
           int left = 0, right = 0;
           if(dp[i][k] != -1)
               left = dp[i][k];
           else
               left = solve(arr, i, k);
           if(dp[k+1][j] != -1)
               right = dp[k+1][j];
           else
               right = solve(arr, k+1, j);

           int temp = left + right + arr[i-1]*arr[k]*arr[j];
           ans = max(ans, temp);
       }
       return ans;
   }
   int matrixMuliplicationCost (vector<int> arr) {
       dp = vector<vector<int>> (arr.size()+1, vector<int> (arr.size()+1, -1));
       return solve(arr, 1, arr.size()-1);
   }
};

class McmPalindromePartition {
   vector<vector<int>> dp;
public:
   bool isPalindrome (string arr, int i, int j) {
       while(i<j) {
           if(arr[i] != arr[j])
               return false;
           i++;
           j--;
       }
       return true;
   }

   int solve (string arr, int i, int j) {
       if(i>=j)
           return 0;
       if(dp[i][j] != -1)
           return dp[i][j];
       if(isPalindrome(arr, i, j))
           return 0;
       int ans = INT_MAX;
       for (int k = i; k<=j-1; ++k) {
           int left = 0, right = 0;
           if(dp[i][k] != -1)
               left = dp[i][k];
           else
               left = solve(arr, i, k);
           if(dp[k+1][j] != -1)
               right = dp[k+1][j];
           else
               right = solve(arr, k+1, j);

           int temp = left + right + 1;
           ans = min(ans, temp);
       }
       return ans;
   }
   int palindromePartition (string arr) {
       dp = vector<vector<int>> (arr.length()+1, vector<int> (arr.length()+1, -1));
       return solve(arr, 0, arr.length()-1);
   }
};

// T^T^F -- no of ways it evaluates to true
class McmParenthesizationMemo {
   unordered_map<string, int> m;
public:
   int solve (string s, int i, int j, bool isTrue) {
       if(i>j)
           return 0;
       if(i==j) {
           if(isTrue) {
               if (s[i] == 'T')
                   return 1;
               else
                   return 0;
           }
           else {
               if (s[i] == 'F') // we might sometimes need subproblem to be false to make whole expression to be true
                   return 1;
               else
                   return 0;
           }
       }
       string temp = to_string(i)+" "+ to_string(j)+" "+ to_string(isTrue);
       if(m.find(temp) != m.end())
           return m[temp];

       int ans = 0;
       for (int k = i+1; k<=j-1; k+=2) {
           int leftT = solve(s, i,k-1,true);
           int leftF = solve(s, i,k-1,false);
           int rightT = solve(s,k+1,j,true);
           int rightF = solve(s, k+1,j, false);
           if(s[k] == '&') {
               ans += (isTrue) ? (leftT*rightT) : (leftF*rightT + leftT*rightF + leftF*rightF);
           }
           if(s[k] == '|') {
               ans += (isTrue) ?  (leftF*rightT + leftT*rightF + leftT*rightT) : (leftF*rightF);
           }
           if(s[k] == '^') {
               ans += (isTrue) ?  (leftF*rightT + leftT*rightF) : (leftT*rightT + + leftF*rightF);
           }
       }
       return m[temp] = ans;
   }
   int Parenthesization (string s) {
       m.clear();
       return solve(s, 0, s.length()-1, true);
   }
};

// see video
class McmScrambledString {
   unordered_map<string, int> m;
public:
   bool solve (string s1, string s2) {
       if(s1.length() != s2.length())
           return false;
       if(s1.compare(s2) == 0)
           return true;
       if(s1.length() <=1 || s2.length() <=1) // <= 1 because if length were to be 1 then the function would have already returned ture if they were equal as well
           return false;
       string temp = s1+' '+s2;
       if(m.find(temp) != m.end())
           return m[temp];
       bool ans = false;
       int n = s1.length(); // since both s1 and s2 are equal take anyone
       for (int k = 1; k <=n-1; ++k) {
           bool part1 = solve(s1.substr(0, k), s2.substr(n-k, k)) && solve(s1.substr(k, n-k), s2.substr(0, n-k));
           bool part2 = solve(s1.substr(0, k), s2.substr(0, k)) && solve(s1.substr(k, n-k), s2.substr(k, n-k));
           if(part1 || part2){
               ans = true;
               break;
           }
       }
       return m[temp] = ans;
   }
   bool Parenthesization (string s1, string s2) {
       m.clear();
       return solve(s1, s2);
   }
};

class eggDropMcm {
   vector<vector< int > > dp;
public:
   int solve(int egg, int floor) {
       if(floor ==1 || floor == 0 || egg == 1)
           return floor;

       if(dp[egg][floor] != -1)
           return dp[egg][floor];
       int ans = INT_MAX, down = 0, up = 0;
       for (int i = 1; i <=floor; ++i) {
           if(dp[egg-1][i-1] != -1)
               down = dp[egg-1][i-1];
           else{
               down = solve(egg-1, i-1);
               dp[egg-1][i-1] = down;
           }
           if(dp[egg][floor-i] != -1)
               up = dp[egg][floor-i];
           else {
               up = solve(egg, floor-i);
               dp[egg][floor-i] = up;
           }

           ans = min(ans, 1+max(up, down)); // max because we have to check for worst case & min because we have to return minimum no. of ways
       }
       return ans;
   }
   int eggDrop(int egg, int floor) {
       dp = vector<vector<int>> (1001, vector<int>(1001, -1));
       return solve(egg, floor);
   }
};

// Dp in binary trees

class diameterOfBT {
public:
   int solve(TreeNode* root, int &res) {
       if(!root)
           return 0;
       int l = solve(root->left, res);
       int r = solve(root->right, res);

       int tentativeAns1 = 1+max(l, r);
       int tentativeAns2 = max(tentativeAns1, 1+l+r);
       res = max(res, max(tentativeAns1, tentativeAns2));
       return tentativeAns1;
   }
   int diameterOfBinaryTree(TreeNode* root) {
       int res = INT_MIN;
       // ans will be saved in res
       solve(root, res);
       return res;
   }
};

class BTPathSum {
public:
   int solve(TreeNode* root, int &res) {
       if(!root)
           return 0;
       int l = solve(root->left, res);
       int r = solve(root->right, res);

       int tentativeAns = max(max(l, r)+root->val, root->val);
       int ans = max(l+root->val+r, tentativeAns);
       res = max(res,ans);
       return tentativeAns;
   }
   int pathSum(TreeNode* root) {
       int res = INT_MIN;
       // ans will be saved in res
       solve(root, res);
       return res;
   }
};

//------------------------------------------------------------------------------------------------------------

// Gold Mine Problem   https://www.geeksforgeeks.org/gold-mine-problem/

int maxGold(int n, int m, vector<vector<int>> M)
{
   // code here
   vector<vector<int>> dp = vector<vector<int>>(n+2, vector<int>(m+2, 0));
   int ans = INT_MIN;
   for(int j = 1; j<=m; j++) {
       for(int i = 1; i<=n; i++) {
           dp[i][j] = M[i-1][j-1] + max(dp[i][j-1], max(dp[i-1][j-1], dp[i+1][j-1]));
       }
   }

   // for(int i = 1; i<=n; i++) {
   //     for(int j = 1; j<=m; j++) {
   //         cout<<dp[i][j]<<" ";

   //     }
   //     cout<<endl;
   // }
   for(int i = 1; i<=n; i++) {
       ans = max(ans, dp[i][m]);
   }

   return ans;
}



int main() {
   return 0;
}

//          a b c b d
//        0 0 0 0 0 0
//     d  0 0 0 0 0 1
//     b  0 0 1 0 1 0
//     c  0 0 0 2 0 0
//     b  0 0 1 0 3 0
//     a  0 1 0 0 0 0





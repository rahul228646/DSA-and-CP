#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

// fixed size sliding window

// 1. given an array return the max sum in a subarray of size k
class maxSumOfSizek {
public:
    int solve(vector<int>arr, int k) {
        int i = 0, j = 0;
        int ans = INT_MIN, sum = 0;
        while(j<arr.size()) {
            //calculation
            sum += arr[j];
            //increasing window size
            if(j-i+1 < k) {
                j++;
            }
            // maintaining window size
            else if(j-i+1 == k) {
                // storing possible answer
                ans = max(sum, ans);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};

// 3. return count of all the anagrams of a word present in the string
class anagramCount {
public:
    int solve(string arr, string pattern) {
        int i = 0, j = 0, k = 0;
        // here window size is the length of pattern
        k = pattern.length();
        // storing count of each character
        unordered_map<char, int> m;
        for(auto l : pattern) m[l]++;

        int ans = 0, count = m.size();
        while(j<arr.size()) {
            //calculation
            m[arr[j]]--;
            if(m[arr[j]] == 0)
                count--;
            //increasing window size
            if(j-i+1 < k) {
                j++;
            }
            // maintaining window size
            else if(j-i+1 == k) {
                // storing possible answer
                if(count == 0)
                    ans++;
                m[arr[i]++];
                if(m[arr[i]]>0)
                    count++;
                i++;
                j++;
            }

        }
        return ans;
    }
};

// 4. given an array return the an array containing max of all subarrays of size k
class maxElementsFromSubOfSizek {
public:
    vector<int> solve(vector<int>arr, int k) {
        int i = 0, j = 0, sum = 0;
        list<int> tentativeMaximum;
        vector<int> ans;
        while(j<arr.size()) {
            //calculation (elements before j which are smaller have to be removed)
            while(!tentativeMaximum.empty() && tentativeMaximum.back()<arr[j]) {
                tentativeMaximum.pop_back();
            }
            tentativeMaximum.push_back(arr[j]);

            //increasing window size
            if(j-i+1 < k) {

                j++;
            }
                // maintaining window size
            else if(j-i+1 == k) {
                // storing possible answer
                ans.push_back(tentativeMaximum.front());
                if(tentativeMaximum.front() == arr[i])
                    tentativeMaximum.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};

//------------------------------------------------------------------------------------------------------------------


// Variable Size Sliding window


// 1. largest subarray of sum k
class largestSubarrayOfSumK {
public:
    int solve(vector<int>arr, int k) {
        int i = 0, j = 0, sum = 0, ans = INT_MIN;
        while(j<arr.size()) {
            sum += arr[j];
            if (sum < k) {
                j++;
            }
            else if (sum == k) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                while(sum > k) {
                    sum -= arr[i];
                    i++;
                }
                if(sum==k){
                    ans = max(ans,(j-i+1));
                }
                j++;
            }
        }
    }

    // for negative
    int lenOfLongSubarr(int arr[],int n,int k){

        // unordered_map 'um' implemented
        // as hash table
        unordered_map<int, int> um;
        int sum = 0, maxLen = 0;

        // traverse the given array
        for (int i = 0; i < n; i++) {

            // accumulate sum
            sum += arr[i];

            // when subarray starts from index '0'
            if (sum == k)
                maxLen = i + 1;

            // make an entry for 'sum' if it is
            // not present in 'um'
            if (um.find(sum) == um.end())
                um[sum] = i;

            // check if 'sum-k' is present in 'um'
            // or not
            if (um.find(sum - k) != um.end()) {

                // update maxLength
                if (maxLen < (i - um[sum - k]))
                    maxLen = i - um[sum - k];
            }
        }

        // required maximum length
        return maxLen;
    }
};


// 2. Longest substr with k unique characters
class kUnique {
public:
    int solve (string s, int k) {
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> m;
        while (j<s.length()) {
            m[s[j]]++;
            if(m.size() < k) {
                j++;
            }
            else if (m.size() == k) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                while (m.size()>k) {
                    m[s[i]]--;
                    if(m[s[i]] == 0) {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

// 3. Longest substr without repeating characters
class allUnique {
public:
    int solve (string s, int k) {
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> m;
        while (j<s.length()) {
            m[s[j]]++;
            if(m.size() < j-i+1) {
                j++;
            }
            else if (m.size() == j-i+1) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                while (m.size()>j-i+1) {
                    m[s[i]]--;
                    if(m[s[i]] == 0) {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// gives tle for 11th test case
// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/submissions/
// https://www.youtube.com/watch?v=9jV0CC_C26s&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe&index=7

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char, vector<int>> mp;
        for(auto i : puzzles) mp[i[0]] = {};
        vector<int> bitmask_word;
        vector<int> bitmask_puzzle;
        for(auto i : words) {
            int mask = 0;
            for(auto j : i) mask |= 1<<(j-'a');
            bitmask_word.push_back(mask);
        }
        for(auto i : puzzles) {
            int mask = 0;
            for(auto j : i) mask |= 1<<(j-'a');
            bitmask_puzzle.push_back(mask);
        }
        for(auto &[c, v] : mp) {
            for(auto i : bitmask_word) {
                if(i & (1<<(c-'a'))) 
                   v.push_back(i);
            }
        }

        // for(auto i : bitmask_word) cout<<i<<" ";
        // cout<<endl;
        // for(auto i : bitmask_puzzle) cout<<i<<" ";
        // cout<<endl;
        
//         for(auto &[c, v] : mp) {
//             cout<<c<<" : ";
//             for(auto i : bitmask_word) {
//                 cout<<i<<" ";
//             }
//             cout<<endl;
//         }
        
        int count = 0;
        vector<int> ans;
        for(int i = 0; i<puzzles.size(); i++) {
            count = 0;
            // cout<<bitmask_puzzle[i]<<" : ";
            for(auto j : mp[puzzles[i][0]]) {
                if((bitmask_puzzle[i] & j) == j) {
                    count++;
                    // cout<<j<<" ";
                }
            }
            // cout<<endl;
            ans.push_back(count);
        }
        return ans;
    }
};

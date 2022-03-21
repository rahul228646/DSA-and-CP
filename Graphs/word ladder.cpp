https://leetcode.com/problems/word-ladder/
https://afteracademy.com/blog/word-ladder-problem

Time : Complexity: O(M²×N), where M is the length of each word, and N is the total number of words in the input word list.

For each word in the word list, we iterate over its length to find all the intermediate words corresponding to it. 
Since the length of each word is M and we have N words, the total number of iterations the algorithm takes to create all_combo_dict is M×N.
Forming each of the intermediate words takes O(M) time because of the substring operation used to create the new string. 
This adds up to a complexity of O(M²×N).
 
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wl) {
        unordered_set<string> dict(wl.begin(), wl.end());
        if(dict.find(end) == dict.end()) return 0;
        queue<string> q;
        q.push(start);
        int ans = 1;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i<n; i++) {
                auto curr = q.front();
                q.pop();
                if(curr == end) return ans;
                for(int j = 0; j<curr.size(); j++) {
                    char c = curr[j];
                    for(int k = 0; k<26; k++) {
                        curr[j] = 'a'+k;
                        if (dict.find(curr) != dict.end()) {
                            q.push(curr);
                            dict.erase(curr);
                        }
                    }
                    curr[j] = c;
                }
                
            }
            ans++;
        }
        return 0;
    }
};

// O(2^N)
class Solution {
public:
    
    vector<vector<int>> ans;
    void solve(vector<int>& c, int start, int t, vector<int> &temp) {
        if(t == 0) {
            ans.push_back(temp);
            return ;
        }
        
        if(start == c.size() || t<0) return;
        
        for(int i = start; i<c.size(); i++) {
            if(i>start && c[i] == c[i-1]) {
                continue;
            }
            if(c[i] > t) break;
       
            temp.push_back(c[i]);
            solve(c, i+1, t-c[i], temp);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<int> temp;
        solve(c, 0, t, temp);
        return ans;
    }
    
};

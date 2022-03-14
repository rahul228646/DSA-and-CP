//https://leetcode.com/problems/simplify-path/submissions/
// Time : O(n) Space : O(n)
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        int i = 0;
        deque<string> q;
        while(i<n) {
            if(path[i] == '/') {
                i++;
                string s;
                while(i<n && path[i] !='/') {
                    s+=path[i++];
                }
                if(s.size() > 0) {
                    if(s=="..") {
                        if(!q.empty()) q.pop_back();
                    }
                    else if(s != ".") {
                        q.push_back(s);
                    }
                }
            }
        }
        string ans;
        while(!q.empty()) {
            ans += '/'+q.front();
            q.pop_front();
        }
        if(ans.size() == 0) return "/";
        return ans;
    }
};

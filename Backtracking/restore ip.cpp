class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        if(s.size()>1 && s[0] == '0') return false;
        if(s.length() > 3) return false;
        if(stoi(s)>255) return false;
        return true;
    }
    void solve(string s, int i, int n, int dots, string &ip) {
        
        if(i == n && dots == 4) {
            ans.push_back(ip.substr(1));
            return;
        }
        if(dots>4) return ;
        for(int k = 0; k<3 && i+k<n; k++) {
            string part = s.substr(i, k+1);
            if(isValid(part)) {
                ip += '.'+part;
                solve(s, i+k+1, n, dots+1, ip);
                int t = 0;
                while(t < part.length()+1) {
                    ip.pop_back();
                    t++;
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ip;
        int n = s.length();
        if(n<4 || n>12) return ans;
        solve(s, 0, s.length(), 0, ip);
        return ans;
    }
};

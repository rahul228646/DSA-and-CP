
// https://practice.geeksforgeeks.org/problems/generate-binary-string3642/1/
class Solution
{
	public:
	    vector<string> ans;
	    void solve(string s, int n) {
	        if(n == 0) return ;
	        solve(s.substr(1, n), n-1);
	        if(s[0] == '?') {
	            if(ans.empty()) {
	                ans.push_back("0");
	                ans.push_back("1");
	            }
	            else {
	                int x = ans.size();
	                for(int i = 0; i<2*x; i++) {
	                    if(i<x) ans[i] = '0'+ans[i];
	                    else ans.push_back('1'+ans[i-x].substr(1));
	                }
	            }
	        }
	        else if(ans.empty()) ans.push_back(s);
	        else for (auto & i : ans) i = s[0] + i;
	       
	    }
		vector<string> generate_binary_string(string s)
		{
		    // Code here
		    solve(s, s.length());
		    return ans;
		    
		}
};

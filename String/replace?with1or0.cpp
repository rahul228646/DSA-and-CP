 
// https://www.geeksforgeeks.org/generate-all-binary-strings-from-given-pattern/

vector<string> ans;
	    
	    void solve (string s) {
	        if(s.length() == 0) return;
	        solve(s.substr(1));
	        if(s[0] == '?') {
	            if(ans.empty()) {
	                ans.push_back("0");
	                ans.push_back("1");
	            }
	            else {
    	            for(int i = 0; i<ans.size(); i++) {
    	                ans[i] = '0'+ans[i];
    	            }
    	            int n = ans.size();
    	            for(int i = 0; i<n; i++) {
    	                string temp = ans[i];
    	                temp[0] = '1';
    	                ans.push_back(temp);
    	            }
	            }
	        }
	        else {
	            if(ans.empty()) {
	                ans.push_back(s);
	            }
	            else {
	                for (auto & i : ans) {
                        i = s[0] + i;
                    }
	            }
	        }
	    }
	    
		vector<string> generate_binary_string(string s)
		{
		    solve(s);
		    return ans;
		}

https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
class Solution {
public:
    vector<string> topologySort(unordered_map<string, vector<string>> adj, unordered_map<string, int> supp) {
        int n = adj.size();
        unordered_map<string, int> in;
        for(auto [i, j] : adj) {
            if(in.find(i) == in.end()) in[i] = 0;
            for(auto k : j) {
                in[k]++;
            }
        }
	    queue<string> q;
        for(auto i : supp) {
            q.push(i.first);
        }
        vector<string> ans;
	    while(!q.empty()) {
	        auto curr = q.front();
	        q.pop();
            if(supp.find(curr) == supp.end())
	        ans.push_back(curr);
	        for(auto i : adj[curr]) {
	            in[i]--;
	            if(in[i] == 0) {
                    q.push(i);
                }
	        }
	    }
	    return ans;
    } 
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ind, vector<string>& s) {
        unordered_map<string, vector<string>> adj;
        for(int i = 0; i<r.size(); i++) {
            for(auto j : ind[i]) {
                adj[j].push_back(r[i]);
                if(adj.find(r[i]) == adj.end()) {
                    adj[r[i]] = {};
                }
            }
        }
        for(auto i : s) {
           if(adj.find(i) == adj.end()) {
               adj[i] = {};
           }
        }
        unordered_map<string, int> supp;
        for(auto i : s) supp[i]++;
        // for(auto i : adj) {
        //     cout<<i.first<<" : ";
        //     for(auto j : i.second) {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return topologySort(adj, supp);
    }
};

// bread->sandwich
//  \       /
//   burger

//https://www.geeksforgeeks.org/dynamic-programming-building-bridges/

// Time : O(nlogn) Space : O(n)
// sort north coord i.e temp.first
// find lis on sourh coord
int non_overlapping_bridges(vector<pair<int,int>> &temp,int n)
{
	sort(temp.begin(),temp.end());
	vector<int> ans;
	ans.push_back(temp[0].second);
	for(int i = 1; i<n; i++) {
	    if(temp[i].second > ans.back()) {
	       ans.push_back(temp[i].second); 
	    }
	    else {
	        int idx = lower_bound(ans.begin(), ans.end(), temp[i].second) - ans.begin();
	        ans[idx] = temp[i].second;
	    }
	}
	return ans.size();	
}

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
     map<int,pair<int,int>>mp;
        for(int i =0; i < intervals.size(); i++){
        mp[intervals[i][0]] = {intervals[i][1],i};
        }
        int n = intervals.size(); 
        vector<int> ans(n,-1);
         for(auto it : mp){
             pair<int,int> p = it.second;
             int st = it.first;
             int en = p.first;
             int ind = p.second;
             auto it1 = mp.lower_bound(en);
             cout<<st<<" "<<en<<" ";
             if(it1 != mp.end())
             {
                 // cout<<ind<<" "<<(*it1).first<<" "<<(*it1).second.second<<"\n";
                 ans[ind] = (*it1).second.second;
             }
         }
        return ans;
    }
};

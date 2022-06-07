Time Complexity: O(n logn) //T(n) = 2T(n/2) + θ(n)
Auxiliary Space: O(n)

class Solution {
public:
    vector<int> merge(vector<int>& a, vector<int>& b) {
        int i = 0,j = 0;
        vector<int> res;
        while(i<a.size() && j<b.size()) {
            if(a[i]<=b[j]) {
                res.push_back(a[i]);
                i++;
            }
            else {
                res.push_back(b[j]);
                j++;
            }
        } 
        if(i<a.size()) for(;i<a.size();i++) res.push_back(a[i]);
        if(j<b.size()) for(;j<b.size();j++) res.push_back(b[j]);
        return res;
    }
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size()<=1) return arr;
        int mid = (arr.size()/2);
        vector<int> v (arr.begin(), arr.begin()+mid);
        auto a = sortArray(v);
        vector<int> t (arr.begin()+mid, arr.end());
        auto b = sortArray(t);
        return merge(a, b);                   
    
    }
};

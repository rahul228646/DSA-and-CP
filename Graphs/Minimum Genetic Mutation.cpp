https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> b(bank.begin(), bank.end());
        int count = 0;
        queue<string> q;
        q.push(start);
        if(b.find(end) == b.end()) return -1;
        b.erase(start);
        while(q.size()) {
            int size = q.size();
            while(size--) {
                auto curr = q.front();
                q.pop();
                cout<<curr<<endl;
                if(curr == end) return count;
                for(int i =0; i<curr.length(); i++) {
                    auto temp = curr;
                    temp[i] = 'A';
                    if(b.find(temp) != b.end()) {
                        q.push(temp);
                        b.erase(temp);
                    }
                    temp[i] = 'C';
                    if(b.find(temp) != b.end()) {
                        q.push(temp);
                        b.erase(temp);
                    }
                    temp[i] = 'G';
                    if(b.find(temp) != b.end()) {
                        q.push(temp);
                        b.erase(temp);
                    }
                    temp[i] = 'T';
                    if(b.find(temp) != b.end()) {
                        q.push(temp);
                        b.erase(temp);
                    }
                    
                } 
            }
            count++;
        }
        return -1;
    }
    
};

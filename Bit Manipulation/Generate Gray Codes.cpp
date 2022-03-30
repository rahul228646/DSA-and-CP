// https://practice.geeksforgeeks.org/problems/generate-grey-code-sequences/1/

vector <string> generateCode(int n){
        if(n == 1) {
            return {"0", "1"};
        }
        vector<string> recAns = generateCode(n-1);
        vector<string> ans;
        for(int i = 0; i<recAns.size(); i++) {
            auto temp = recAns[i];
            ans.push_back("0"+temp);
        }
        
        for(int i = recAns.size()-1; i>=0; i--) {
            auto temp = recAns[i];
            ans.push_back("1"+temp);
        }
        return ans;
    }

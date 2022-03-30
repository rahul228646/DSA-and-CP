// https://practice.geeksforgeeks.org/problems/generate-grey-code-sequences/1/
// Time : O(N^2)
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
gray code for
1 bit - 0 1
2 bit - 00 01 11 10 
3 bit - 000 001 011 010 110 111 101 100   // in each subsequent term there is differnce in only one bit     

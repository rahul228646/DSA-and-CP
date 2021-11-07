// https://leetcode.com/problems/multiply-strings/solution/
// Time : O(M*(M+N)) Space : O(M+N)

class Solution {
public:

    vector<int> addStrings (vector<int> num1, vector<int> num2) {
        int n1 = num1.size(), n2 = num2.size();
        int i = 0, carry = 0;
        vector<int> ans;
        while (i<n1 || i<n2) {
            int digit1 = i < num1.size() ? num1[i] : 0;
            int digit2 = i < num2.size() ? num2[i] : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum/10;
            ans.push_back(sum % 10);
            i++;
        }
        if(carry) ans.push_back(carry);
        return ans;
    }

    vector<int> mulOneDigit (string& firstNumber, char& secondNumberDigit, int numZeros) {
        vector<int> currentResult(numZeros, 0); // appending zeros in infront
        int carry = 0;
        for (char firstNumberDigit : firstNumber) {
            int multiplication = (secondNumberDigit - '0') * (firstNumberDigit - '0') + carry;
            carry = multiplication / 10;
            currentResult.push_back(multiplication % 10);
        }

        if (carry) currentResult.push_back(carry);
        return currentResult;
    }

    string multiply(string n1, string n2) {
        
        if(n1=="0"||n2=="0") return "0";
        
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        
        vector<int> ans(n1.size()+n2.size(), 0);

        for(int i = 0; i<n2.size(); i++) {
           vector<int> mulAns = mulOneDigit(n1, n2[i], i);
           ans = addStrings(mulAns, ans); 
        }
        while(ans.back() == 0) ans.pop_back();
        string answer;
        for (int i = ans.size() - 1; i >= 0; --i) {
            answer.push_back(ans[i] + '0');
        }
        return answer;
    }
};

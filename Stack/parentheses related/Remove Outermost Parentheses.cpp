
 class Solution {
public:
    string removeOuterParentheses(string S) {
        int c = 0;
        int len = S.size();
        string res;
        
        for (int i = 0; i < len; i++) {
            
            if (S[i] == '(') {
                c++;
            } else {
                c--;
            }
            
            if (c == 1 and S[i] == '(')
                continue;
            if (c == 0 and S[i] == ')')
                continue;
            
            res += S[i];
            
        }
        
        return res;
    }
};

->    ( (  )   (    )    )     (    (      )       )
c   : 1 2  1   2    1    0     1    2      1       0
res :   (  ()  ()(  ()() ()()  ()() ()()(  ()()()  ()()()


class Solution {
public:
  
    int calculate(string s) {
        int result=0; 
        int num=0, sign=1; 
        stack<int> nums, ops; 
        
        for(auto c : s){
            if(isdigit(c)){
                num=10*num + (c-'0'); /// For case: "23" 
            }
            else if(c=='+'){
                result+=num*sign; /// everytime meets an operator, sum up previous number
                num=0;
                sign=1;    /// sign is the sign of next number
            }
            else if(c=='-'){
                result+=num*sign; /// everytime meets an operator, sum up previous number
                num=0; 
                sign=-1; 
            }
            else if(c=='('){
                nums.push(result); /// ...(1+3+(..xx..)+...)... before go into cur (..xx..), record the forefront result (in this case it is 1+3 ) into nums array    
                ops.push(sign);  // record cur (..xx..) sign
                result=0;  // result is to record the total value in the cur (..xx..)
                sign=1;
            }
            else if(c==')' && ops.size()){ 
                result+=num*sign; /// For case: 1-(5)
                num=0;
                
                result = result*ops.top() + nums.top();  // ...(1+3+(..xx..)+...)... sum up cur (..xx..)  and the forefront result (in this case it is 1+3 )
                nums.pop();
                ops.pop();
            }
        }
        result+=num*sign; /// For the last one operation. consider the case:  1+2+3 
        return result; 
    }
};

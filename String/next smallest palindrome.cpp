// https://practice.geeksforgeeks.org/problems/next-smallest-palindrome4740/1/?problemStatus=unsolved&page=1&company[]=Media.net%20&query=problemStatusunsolvedpage1company[]Media.net

bool all9(int num[], int n) {
	for(int i = 0; i<n; i++) {
            if(num[i]!=9) return false;
        }
        return true;
} 
	vector<int> generateNextPalindrome(vector<int> num, int n) {
	
    // case 1 - all elements are 9 ex - 999 therefore next smallest palindrome would be 10001
	    if(all9(num, n)) {
	        vector<int> ans(n, 9);
	        ans[0] = 1;
	        ans.push_back(1);
	        return ans;
	    }
   //  1 2 3 4 5 -- left part 1 2 ; right part 4 5 ;
  //   1 2 3 4 5 6 -- left part 1 2 3 ; right part 4 5 6 ; 
	    int mid = n/2;
	    int lEnd = mid-1;
	    int rStart = (n%2 == 0) ? mid : mid+1;
	    bool leftsmaller = false;
 
	   // cout<<lEnd<<" "<<rStart<<endl;
//     skip over all middle palindrome
	    while(lEnd>=0 && num[lEnd] == num[rStart]) {
	        lEnd--;
	        rStart++;
	    }
//     if lEnd < 0 the the no was already palindrome then leftsmaller will be true;
//     if num[lEnd] < num[rStart].    9 8 7 |6 5 6| 8 8 9   or   9 4 7 |6 5 6| 8 8 3 1    === 7<8   then leftsmaller will be true;
	    if (lEnd < 0 || num[lEnd] < num[rStart])
            leftsmaller = true;
            
	    while(lEnd>=0) {
	        num[rStart] = num[lEnd];
	        lEnd--;
	        rStart++;
	    }
	   // for(int i = 0; i<n; i++) cout<<num[i]<<" ";
	   // cout<<endl;
    
//   if leftsmaller was be true;
//     we need further processing -- add 1 to the middle , since middle can be 9 we will have take over the carry on both sides
	    if(leftsmaller) {
	        int carry = 1;
	        if(n%2 != 0) {
	            num[mid]+=carry;
	            carry = num[mid]/10;
	            num[mid] %= 10;
	            lEnd = mid-1;
	            rStart = mid+1;
	        }
	        else {
	            lEnd = mid-1;
	            rStart = mid;
	        }
	        while(lEnd>=0) {
	            num[lEnd]+=carry;
	            carry = num[lEnd]/10;
	            num[lEnd] %= 10;
	            num[rStart++] = num[lEnd--];
	        }
	    }
	    
	    return num;
	}

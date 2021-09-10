
#include <iostream>
#include <math.h>
using namespace std;

//1. power
int power(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }
    return x * power(x,n-1);
}

//2.  code to find out and return the number of digits present in a number recursively.
int count(int n){
    if(n<=0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}

//3. Given an array of length N, you need to find and return the sum of all elements of the array.
int sum(int input[], int n) {
    if(n==0)
    {
        return 0;
    }
    return input[0] + sum(input+1,n-1) ;
}

//4. Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
bool checkNumber(int input[], int size, int x) {
    if(size <= 0)
        return false;
    if(input[0] == x)
        return true;
    return checkNumber(input+1, size-1, x);
}

//5. Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
int firstIndex(int input[], int size, int x) {
    if(size == 0)
        return -1;
    if(input[0] ==  x)
        return 0;
    int ans = firstIndex(input+1, size-1, x);
    if(ans == -1)
        return ans;
    return 1+ans;
}

//6. Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
int lastIndex(int input[], int size, int x) {
    if(size==0)
        return -1;
    int ans = lastIndex(input+1,size-1,x);
    if(ans == -1){
        if(input[0]==x)
            return ans+1;
        else
            return ans;
    }
    return ans+1;
}

//7. Given two integers m & n, calculate and return their multiplication using recursion
int multiplyNumbers(int m, int n) {
    if(n == 0 || m == 0)
        return 0;
    return m + multiplyNumbers(m, n-1);
}
//8. Given an integer n, count and return the number of zeros that are present in the given integer using recursion
int countZeros(int n) {
    if(n == 0)
        return 0;
    if(n % 10 == 0)
        return 1 + countZeros(n/10);
    return countZeros(n/10);
}

//9. Given k, find the geometric sum i.e.
//1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
//3
//1.875
double geometricSum(int k) {
    if(k == 0)
        return 1;
    return 1/pow(2,k) + geometricSum(k-1);
}

//10. Check if a given String S is palindrome or not (using recursion). Return true or false.
bool checkPalindrome(char s[], int start, int end){
    if(s[start]!=s[end])
        return false;
    else if(start>end)
        return true;
    else
        return checkPalindrome(s,start+1,end-1);
}

//11. Write a recursive function that returns the sum of the digits of a given integer.
int sumOfDigits(int n) {
    if(n == 0)
        return 0;
    
    return n % 10 + sumOfDigits(n/10);
}
//12. Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
//5
//9 8 10 8 8
//8
//1 3 4

int allIndexes(int input[], int size, int x, int output[]) {
    if(size==0)
        return 0;
    int ans = allIndexes(input+1,size-1,x,output);
     for(int i=0; i<ans;i++)
            output[i]+=1;
    
    if(input[0]==x){
        for(int i=ans;i>0;i--){
            output[i]=output[i-1];
        }
        output[0]=0;
            return ans+1;
    }
    else
        return ans;
}

//13. Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// xpix          pip
// x3.14x        3.14p
int len(char input[]){
    return strlen(input);
}

void replacePi(char input[]){

    if(input[0]==0){
        return ;
    }
    if(input[0]=='p' && input[1]=='i'){
        int count=0;
        while(count!=2)
        {
         int n=len(input);
         for(int i=n;i>0;i--){
              input[i]=input[i-1];
          }
            count++;
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
        replacePi(input+4);
        
    }
    replacePi(input+1);
    return;
}

//14. Given a string, compute recursively a new string where all 'x' chars have been removed.
void removeX(char input[]) {
    if(input[0] == '\0')
        return ;
    if(input[0] == 'x'){
        for (int i=0; i<len(input); i++) {
            input[i] = input[i-1];
        }
    }else{
        return removeX(input+1);
    }
    return removeX(input);
}

//15. Write a recursive function to convert a given string into the number it represents. i.e. string to int
int stringToNumber(char input[]) {
    if(input[0] == '\0')
        return 0;
    int ans = stringToNumber(input+1);
    int firstDigit = input[0] - 48;
    int smallcalculation = firstDigit * pow(10, strlen(input)-1) + ans;
    return smallcalculation;
}

//16. Tower of hanoi

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==0)
        return;
    
    return towerOfHanoi(n-1,source, destination, auxiliary);
    return towerOfHanoi(n-1,auxiliary, source, destination );
}

//17. identical chars that are adjacent in the original string are separated from each other by a "*".
// xxyy    aaaa     hello
// x*xy*y  a*a*a*a  hel*lo
void pairStar(char input[]) {
    if(input[0] == '\0')
        return ;
    if(input[0] == input[1]){
        input[len(input)+1] = '\0';
        for (int i=len(input); i>0; i--) {
            input[i] = input[i-1];
        }
        input[1] = '*';
    }
    return pairStar(input + 1);
}

int main(){
    char input[] = "aaaa";
    pairStar(input);
    cout<<input;
}



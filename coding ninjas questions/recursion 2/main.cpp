
#include <iostream>
#include <cstring>
using namespace std;
//1. Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with    character c2 in the given string.
//    abacd
//    a x
//    xbxcd
void replaceCharacter(char input[], char c1, char c2) {
    if(input[0] == '\0')
        return;
   replaceCharacter(input+1, c1, c2);
    if(input[0] == c1)
        input[0] = c2;
    return;
}

//2. Given a string S, remove consecutive duplicates from it recursively.
void removeConsecutiveDuplicates(char *input) {
   if(input[0] == '\0')
       return;
    if(input[0] == input[1]){
        for(int i=0 ; input[i]!='\0'; i++){
            input[i+1]=input[i+2];
        }
       return removeConsecutiveDuplicates(input);
    }else{
        return removeConsecutiveDuplicates(input+1);
    }
}

//3. Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
//a. The string begins with an 'a'
//b. Each 'a' is followed by nothing or an 'a' or "bb"
//c. Each "bb" is followed by nothing or an 'a'
bool checkAB(char input[]) {
    if(input[0]=='\0')
        return true;
    
  if(input[0]=='a'){
    if(input[1]=='b' && input[2]=='b')
        return checkAB(input+3);
      
    else if(input[1]=='\0')
        return true;
      
    else if(input[1]=='a')
        return checkAB(input+1) ;
        
    else
        return false;
    }
    else
        return false;
 
}
//4.Achild is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
//    4
//    7
int staircase(int n){
    if(n <= 0)
        return 0;
    if(n == 0)
        return 1;
    int ans1 = staircase(n-1); // 1 step
    int ans2 = staircase(n-2); // 2 steps
    int ans3 = staircase(n-3); // 3 steps
    
    return ans1 + ans2 + ans3;
}

//5.Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
//  Return empty string for numbers 0 and 1.
//    23
//    ad ae af bd be bf cd ce cf

void assignment(int n,char code[10])
{
    int j=0;
    switch (n) {
        case 2:
            j=0;
            while(j<3)
            {
            code[j]='a'+j;
                j++;
            }
            break;
            
            case 3:
            j=0;
            while(j<3)
            {
            code[j]='d'+j;
                j++;
            }
            break;

            case 4:
            j=0;
            while(j<3)
            {
            code[j]='g'+j;
                j++;
            }
            break;

            case 5:
            j=0;
            while(j<3)
            {
            code[j]='j'+j;
                j++;
            }
            break;

            case 6:
            j=0;
            while(j<3)
            {
            code[j]='m'+j;
                j++;
            }
            break;

            case 7:
            j=0;
            while(j<4)
            {
            code[j]='p'+j;
                j++;
            }
            break;

            case 8:
            j=0;
            while(j<3)
            {
            code[j]='t'+j;
                j++;
            }
            break;

            case 9:
            j=0;
            while(j<4)
            {
            code[j]='w'+j;
                j++;
            }
            break;

        default:
            break;
    }
}

int keypad(int num, string output[]){

      if(num==0 || num==1)
    {
        output[0]="";
        return 1;
    }
    int last_digit=num%10;
    int small_output = keypad(num/10,output);
    
    char code[10];
    assignment(last_digit,code);
    
     if(last_digit==7 || last_digit==9)
     {
               int x=small_output;
                      int j=1;
                      while(j<=3)
                      {
                        for(int i=0;i<small_output;i++)
                        {
                          output[x+i]=output[i]+code[j];
                        }
                          j++;
                          x=j*small_output;
                      }
                      
                      for (int i=0; i<small_output; i++) {
                          output[i]=output[i]+code[0];
                      }
         return 4*small_output;

    }
               
    else
    {
        int x=small_output;
        int j=1;
        while(j<=2)
        {
          for(int i=0;i<small_output;i++)
          {
            output[x+i]=output[i]+code[j];
          }
            j++;
            x=j*small_output;
            
        }
        
        for (int i=0; i<small_output; i++) {
            output[i]=output[i]+code[0];
        }
        
        return 3*small_output;
    }
 
    
   
}
//6. Return subset of an array
//    3
//    15 20 12
//    [] (empty array) (12) (20) (20 12) (15) (15 12) (15 20) (15 20 12)
 int subset(int input[], int n, int output[][20])
{
  
    if (n==0) {
        output[0][0]=0;
        return 1;
    }
    

    int s1 = subset(input+1, n-1, output);
      
    for(int i=s1; i<2*s1; i++)
         {
             output[i][0]=1+ output[i-s1][0];
             output[i][1] = input[0];
             for(int j=1; j<=output[i-s1][0];j++)
             {
                 output[i][j+1]=output[i-s1][j];
                 
             }
            
         }
       
       
    return 2*s1;
     
 }

// or


vector<vector<int>> subsets(vector<int>& nums) {

    if(nums.size() == 0){
        vector<vector<int>>temp;
        vector<int>v;
        temp.push_back(v);
        return temp;
    }

    int num = nums[0];
    nums.erase(nums.begin());

    vector<vector<int>>sub1 = subsets(nums);
    vector<vector<int>>subset;

    for(vector<int>sub : sub1){
        subset.push_back(sub);
        sub.push_back(num);
        subset.push_back(sub);
    }

    return subset;
}

//7. Return subsets sum to K
int subsetSumToK(int input[], int n, int output[][50], int k) {

   if(n==0)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        else
            return 0;
    }
    
    int o1[1000][50];
    int o2[1000][50];
    
    int s2 = subsetSumToK(input+1, n-1, o1 , k-input[0]);
   
    int s1 = subsetSumToK(input+1, n-1, o2 , k);
    
    
int m=0;
    for(int i=0; i<s1; i++)
    {
        
        for(int j=0; j<=o2[i][0];j++)
        {
            output[m][j]=o2[i][j];
        }
        m++;
    }
    
    
    for(int i=0; i<s2; i++)
    {
        output[m][0]=1+ o1[i][0];
        output[m][1] = input[0];
        
        for(int j=1; j<=o1[i][0];j++)
        {
            output[m][j+1]=o1[i][j];
            
        }
        m++;
        
    }
    return m;

}




//8. Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// 1123 (aabc) (kbc) (alc) (aaw) (kw)
    char code_1[30];

char getAlpha(int n)
{
   for(int i=1;i<=26;i++)
   {
       code_1[i]=('a');

       code_1[i]=code_1[i]+i-1;
   }
    
    return code_1[n];
}

int getCodes(string input, string output[10000]) {
    if(input.length() == 1){
        int n =input[0]-'0';
        if(n<0 || n>10)
        {
            return 0;
        }
        char c= getAlpha(n);
        
        output[0]=c;
        return 1;
    }
    
    if(input.length() == 0)
        return 1;
    int n;
    char c;
    
    int total1=getCodes(input.substr(1), output);
    n =input[0]-'0';
    c= getAlpha(n);
    for(int i=0;i<total1;i++)
    {
        output[i]=c+output[i];
    }
    int a=input[0]-'0';
    int b=input[1]-'0';
    int d=a*10+b;
    if(d>26)
        return total1;
    
    int total2=total1+getCodes(input.substr(2), output+total1);
    int n1 =input[0]-'0';
    int n2 =input[1]-'0';
    n=n1*10+n2;
    c= getAlpha(n);
    
    for(int i=total1;i<total2;i++){
        output[i]=c+output[i];
    }
    
    return total2;
}

//8. Return Permutations - String
//abc (abc) (acb) (bac) (bca) (cab) (cba)
int returnPermutations(string input, string output[]){
    if(input[0] == '\0')
        return 0;
    if(input.length() == 1){
        output[0] = input[0];
        return 1;
    }
    char c=input[0];
    int total=returnPermutations(input.substr(1), output);
//    char c=input[0]; //answer is same as above
    string temp[1000];
    for(int i=0 ; i<total ; i++){
        temp[i]=output[i];
    }
      
    int k=0;
    for(int i=0; i<total;i++){
        for(int j=0;j<=temp[0].length();j++){
            output[k++]=temp[i].substr(0,j)+c+temp[i].substr(j);;
        }
    }
    return k;
}

int main(int argc, const char * argv[]) {
    string s1 = "abc";
    string *s2 = new string[1000];
    int s = returnPermutations(s1, s2);
    for(int i = 0; i<s; i++)
        cout<<s2[i]<<endl;
}

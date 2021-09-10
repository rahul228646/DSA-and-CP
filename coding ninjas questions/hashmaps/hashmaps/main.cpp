
#include<iostream>
#include<unordered_map>

using namespace std;

int highestFrequency(int *input, int n){
    unordered_map<int, int> m;
    for(int i =0; i<n; i++){
        m[input[i]]++;
    }
    
    int max = input[0];
    for(int i = 0; i<n; i++){
        if(m.count(max) < m.count(input[i])){
            max = input[i];
        }
    }
    return max;
}

void intersection(int input1[], int input2[], int size1, int size2) {
   unordered_map<int, bool> m;
    
   for(int i =0; i<size1; i++){
       m[input1[i]] = true;
   }
    
    for(int i =0; i<size2; i++){
        if(m.count(input2[i]) >0){
            cout<<input2[i]<<endl;
            m[input2[i]] = false; 
            
        }
    }

}

#include<unordered_map>
#include <cstring>
char* uniqueChar(char *str){
   unordered_map<char, bool> m;
   for(int i =0; i<strlen(str); i++){
       m[str[i]] = true;
   }
    int j=0;
    for(int i =0; i<strlen(str); i++){
        if(m[str[i]]){
            str[j++] = str[i];
            m[str[i]] = false;
        }
    }
    str[j] = '\0';
    return str;
}

void PairSum(int *input, int n) {
    
    unordered_map<int, int> m;
    for(int i =0; i<n; i++){
        m[input[i]]++;
    }
    
    for(int i =0; i<n; i++){
        int num = 0 - input[i];
        if(m.count(num)>0){
            int j = m[num];
            for(int k =0; k<j; k++){
                if(num < 0)
                    cout<<num<<" "<<input[i]<<endl;
                else
                    cout<<input[i]<<" "<<num<<endl;
            }
            m[input[i]]--;
        }
    }
}

#include <vector>


vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
    
    vector<int> v;
    unordered_map<char, bool> m;  
    for(int i =0; i<n; i++){
        m[arr[i]] = true;
    }
    
    int maxLength = 0;
    int length = 0;
    int currentans = 0;
    int ans = 0;
    int ansfinal = 0;
    for(int i = 0; i<n; i++){
        
        if(m[arr[i]]){
            length = 0;
            int j = arr[i];
            currentans = arr[i];
            while(m[j]){
                m[j] = false;
                length++;
                j++;
            }
            ans = currentans;
            
            j = arr[i]-1;
            if(m.count(j)){
            while(m[j]){
                m[j] = false;
                length++;
                
                j--;
            }
                currentans = j+1;
            }
            if(currentans == ans && maxLength <= length){
                maxLength = length;
                ansfinal = ans;
            }
            else if(maxLength < length){
                maxLength = length;
                ansfinal = currentans;
            }
         
        }
    }

    for(int i = 0; i<maxLength; i++){
        v.push_back(ansfinal);
        ansfinal++;
    }
    
    return v;

}

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
    unordered_map<int, int> m;
    int sum = 0;
    int maxLength = 0;
    for(int i =0; i<size; i++){
        sum += arr[i];
        if(m.count(sum)==0){
            m[sum] = i;
        }
        else{
            maxLength = i - m[sum];
        }
    }
    return maxLength;
}



int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
    cout << *it <<endl;
  }

  delete arr;
}

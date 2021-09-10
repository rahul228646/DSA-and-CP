#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <stack>
#include <list>
using namespace std;
#define prt(x) cout<<(x)<<endl;
#define srtInc(v) sort((v).begin(), (v).end());
#define srtDec(v) sort((v).begin(), (v).end(), greater<>();
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
//#define vll vector<long long> vll;
//#define vi vector<long long>;
//#pragma comment(linker, "/STACK:2000000000")
typedef long long ll;


int nXOR (int);

void solve () {
   ll t;
   cin>>t;
   while(t--) {
     int n;
     cin>>n;
     string s;
     cin>>s;
     vector<vector<char>> arr(n, vector<char>(n, 'e'));
     unordered_map<int, bool> m;
     for(int i = 0; i<n; i++) {
         if(s[i] == '2') {
             m[i] = false;
         }
     }
     for(int i = 0; i<n; i++) {
         for(int j = 0; j<n; j++) {
             if(i == j) {
                 arr[i][j] = 'X';
                 continue;
             }
             if(s[i] == '2') {
                 if(arr[i][j] != 'e') {
                     continue;
                 }
                 if(s[j] == '1') {
                     arr[i][j] = '-';
                     arr[j][i] = '+';
                     continue;
                 }
                 if(s[j] == '2') {
                     if(!m[i]) {
                         arr[i][j] = '+';
                         arr[j][i] = '-';
                         m[i] = true;
                     }
                     else {
                         arr[i][j] = '-';
                         arr[j][i] = '+';
                         m[j] = true;
                     }
                     continue;
                 }
             }
             else if (s[i] == '1') {
                 if(arr[i][j] != 'e') {
                     continue;
                 }
                 arr[i][j] = '=';
                 arr[j][i] = '=';
             }
         }
     }
     bool flag = true;
     for(auto i : m) {
         if(!i.second) {
             flag = false;
         }
     }
     if(flag) {
         yes;
         for(int i = 0; i<n; i++) {
             for (int j = 0; j < n; j++) {
                 cout<<arr[i][j];
             }
             cout<<endl;
         }
     }
     else {
         no;
     }
   }
}

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<unordered_map<int, int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                long long diff = a[i] - a[j];
                if (diff >= INT_MIN || diff <= INT_MAX) continue;
                if (dp[j].find((int) diff) != dp[j].end()) {
                    ans += dp[j][(int) diff];
                    dp[i][(int) diff] += 1;
                } else {
                    dp[i][(int) diff] = 1;
                }
            }
        }
        return ans;
    }
    };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

int nXOR(int n){
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

//class Solution  {
//public:
//    static bool cmp(char x, char y) {
////        cout<<x<<y<<endl;
//        if((x == 'C' && y == 'D') || (x == 'D' && y == 'C')) {
//            return true;
//        }
//        else if((x == 'A' && y == 'B') || (x == 'B' && y == 'A')) {
//            return true;
//        }
//        return false;
//    }
//    static string solution (string s) {
//        int n = s.length();
//        if(n <= 1) return s;
//        stack<char> st;
//        st.push(s[0]);
//        for(int i = 1; i<n; i++) {
//            if(st.empty()) {
//                st.push(s[i]);
//                continue;
//            }
//            char c = st.top();
//            if(cmp(s[i], c)) {
//                st.pop();
//            }
//            else {
//                st.push(s[i]);
//            }
////          cout<<st.top()<<endl;
//        }
//        string ans;
//        while(!s.empty()) {
//            ans += st.top();
//            st.pop();
//        }
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//};

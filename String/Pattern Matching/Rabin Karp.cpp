// generating hash
abc
p = prime no. greater than the range of characters i.e. 
for small letters 1-26 take p {29, 31, ....} 
for both letters 1-52 take p {29, 31, ....} 

(a-'a'+1)*(p)^0  + (b-'a'+1)*(p)^1 + (c-'a'+1)*(p)^2

int hash(string s) {
  int n = s.length();
  int ans = 0;
  int mod = 1e9+7;
  int p = 31;
  int pow = 1;
  for(int i = 0; i<n; i++) {
    ans = (ans + (s[i]-'a'+1)*pow) % mod;
    pow = (pow*p) % mod;
  }
  return ans;
}

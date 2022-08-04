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

//-------------------------------------------------------------------------------

void rabinCarp (string text, string pattern) {
    long long n = text.length(), m = pattern.length();
    long long mod = 1e9+7, p = 31, pow = 1, desiredHash = 0;

    for(int i = 0; i<m; i++) {
        desiredHash = (desiredHash + (pattern[i]-'a'+1)*pow) % mod;
        pow = (pow*p) % mod;
    }

    vector<long long> prefixHash(n, 0);
    vector<long long> power(n, 0);
    power[0] = 1;
    pow = p;
    prefixHash[0] = text[0]-'a'+1;

    for(int i = 1; i<n; i++) {
        prefixHash[i] = (prefixHash[i-1] + (text[i] - 'a' + 1) * pow) % mod;
        power[i] = pow;
        pow = (p*pow)%mod;
    }
    // sliding window
    vector<int> positions_at_which_pattern_was_found;
    int i = 0, j = m-1;
    for(; j<n; j++) {
        long long window_hash = prefixHash[j];

        if(i>0) window_hash = (prefixHash[j] - prefixHash[i-1] + mod) % mod; //mod is added so that the difference doesn't become negative
        if(window_hash == ( (desiredHash*power[i]) % mod ) ) {

            positions_at_which_pattern_was_found.push_back(i+1); // i + 1 for 1 based indexing
        }
        i++;
    }

    for(auto x : positions_at_which_pattern_was_found) cout<<x<<" ";
    cout<<endl;
}

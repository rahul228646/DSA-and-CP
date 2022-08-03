
// Time : O(n + m) Space : O(m)

void KMP(string pattern, string txt)
{
	int n = txt.length(), m = pattern.length();

	vector<int> lps(m, 0);

	computeLPSArray(pattern, m, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < n) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == m) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < n && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int m, vector<int> &lps)
{
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
  	for(int i = 0; i<M; i++) std::cout<<lps[i]<<" ";
}

------------------------------------------------------------------------------------------------------------------------------------------

return occurances

void findLps(vector<int> &lps, string p, int m) {
    int i = 0, j = 1;
    lps[0] = 0;
//    cout<<i<<" "<<j<<endl;
    while(j<m) {
//        cout<<i<<" "<<j<<endl;
        if(p[i] == p[j]) {
            i++;
            lps[j] = i;
            j++;
        }
        else {
            if(i != 0) {
                i = lps[i - 1];
            }
            else {
                lps[j] = 0;
                j++;
            }
        }
    }
}

int kmp(string t, string p) {
    int n = t.length(), m = p.length();
    vector<int> lps(m, 0);
//    cout<<1;
    findLps(lps, p, m);

    int i = 0, j = 0;
    int count = 0;
    while(i<n) {
        if(t[i] == p[j]) {
            i++;
            j++;
        }
        if(j == m) {
            count++;
            j = lps[j-1];
        }
        else if(i<n && p[j] != t[i]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return count;
}

int main() {
    int n, q;
    cin>>n>>q;
    string t;
    cin>>t;
    vector<int> ans;
    while(q--) {
        string p;
        cin>>p;
        ans.push_back(kmp(t, p));
    }
    for(auto i : ans) cout<<i<<endl;
    return 0;
}


7 5
acababa
a
bb
caba
aba
karp
4
0
1
2
0


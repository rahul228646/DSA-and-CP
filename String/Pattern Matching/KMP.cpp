
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



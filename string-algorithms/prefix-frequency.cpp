#include<bits/stdc++.h>

using namespace std;

vector<int> ComputeLPS(string &str) {
	int str_len = str.size();

	vector<int> lps(str_len);

	lps[0] = 0;

	for(int i=1; i<str_len; i++) {
		int j = lps[i-1];

		while(true) {
			if(str[j] == str[i]) {
				lps[i] = j+1;
				break;
			}

			else if(j!=0) {
				j = lps[j-1];
			}

			else {
				break;
			}
		}	
	}

	return lps;
}


vector<int> ComputePrefixFrequency(string &str) {
	int str_len = str.size();

	vector<int> lps = ComputeLPS(str);
	
	vector<int> prefix_count(str_len, 0);

	// Calculation of number of times a prefix has
	// been a proper suffix of any other larger prefix.
	for(int i=str_len-1; i>=0; i--) {
		if(lps[i]) {
			prefix_count[lps[i]-1] += prefix_count[i] + 1;
		}
	}

	// Count for prefix itself
	for(int i=0; i<str_len; i++) {
		prefix_count[i]++;
	}

	for(auto i: prefix_count) {
		cout << i << " ";
	}

	return prefix_count;
}

int main() {
	string str = "abcdabcdabcd";
	ComputePrefixFrequency(str);
}
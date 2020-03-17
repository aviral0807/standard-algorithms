#include <bits/stdc++.h>

using namespace std;

vector<int> ComputeLPS(string &str) {
	int str_len = str.size();

	vector<int> lps(str_len);

	lps[0] = 0;

	for(int i = 1; i < str_len; i++) {
		int j = lps[i-1];
		while(true) {
			if(str[j] == str[i]) {
				lps[i] = j + 1;
				break;
			}
			else if(j != 0) {
				j = lps[j-1];
			}
			else {
				lps[i] = 0;
				break;
			}
		}
	}

	return lps;
}

bool KnuthMorrisPratt(string &text, string &pattern) {
	int text_len = text.size();
	int pattern_len = pattern.size();

	vector<int> lps_pattern = ComputeLPS(pattern);

	int j = 0;

	for(int i = 0; i < text_len; i++) {	
		while(true) {
			if(pattern[j] == text[i]) {
				j++;
				break;
			}
			else if(j != 0) {
				j = lps_pattern[j-1];
			}
			else {
				break;
			}
		}

		if(j == pattern_len) {
			return true;
		}
	}

	return false;
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

	return prefix_count;
}

int main() {
	
	string text = "ddaacdaacaddaacadedd";
	string pattern = "daacade";

	cout << "Pattern Search Result - " << KnuthMorrisPratt(text, pattern) << endl;

	cout << "Prefix Frequency - \n";
	for(auto i: ComputePrefixFrequency(text)) {
		cout << i << " ";
	}

	return 0;
}
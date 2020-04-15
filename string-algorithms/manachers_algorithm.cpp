#include <bits/stdc++.h>

using namespace std;

string LongestPalindromicSubstring(string& str) {
	string new_str = "#";
	for(auto c: str) {
		new_str.push_back(c);
		new_str.push_back('#');
	}

	int n = new_str.size();
	vector<int> p(n,0);

	int l = 0, r = 0, max_len = 0, max_len_st = 0;
	for(int i = 1; i < n; i++) {
		if(i<r) {
			p[i] = min(p[l+r-i], r-i);
		}

		while(i + p[i] + 1 < n and i - p[i] - 1 >= 0 and new_str[i+p[i]+1] == new_str[i-p[i]-1]) {
			p[i]++;
		}

		if(i + p[i] > r) {
			r = i + p[i];
			l = i - p[i];
		}

		if(p[i] > max_len) {
			max_len = p[i];
			max_len_st = (i - p[i] + 1) / 2;
		}
	}

	return str.substr(max_len_st, max_len);
}

int main() {
	string s = "ababababbbababa";

	cout << LongestPalindromicSubstring(s);

	return 0;
}
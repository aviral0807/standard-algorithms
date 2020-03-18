#include <bits/stdc++.h>

using namespace std;

vector<int> ComputeZArray(string &str) {
	int str_len = str.size();

	vector<int> z(str_len, 0);

	int l=0, r=0;

	for(int i=1; i<str_len; i++) {
		if(i <= r) {
			z[i] = min(z[i-l], r-i+1);
		}
		while(i+z[i]<str_len and str[i+z[i]] == str[z[i]]) {
			z[i]++;
		}
		if(i+z[i]-1 > r) {
			r = i+z[i]-1;
			l = i;
		}
	}

	return z;
}

int main() {
	string text = "aabbaabcaabbaacda";

	cout << "Z Array - \n";
	for(auto i: ComputeZArray(text)) {
		cout << i << " ";
	}
}
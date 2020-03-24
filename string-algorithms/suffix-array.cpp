#include <bits/stdc++.h>

using namespace std;

vector<int> ComputeSuffixArray(string s) {
	s = s + '$';

	int n = s.size();

	vector<pair<pair<int, int>, int>> entry(n);
	vector<int> rank(n);

	for(int i = 0; i < n; i++) {
		entry[i] = {{s[i], 0}, i};
	}

	int step = 0;
	while((1<<step) < 2*n) {
		sort(entry.begin(), entry.end());

		int cur_rank = 0;
		pair<int, int> cur_entry = entry[0].first;
		for(int i = 0; i < n; i++) {
			int position = entry[i].second;
			if(entry[i].first == cur_entry) {
				rank[position] = cur_rank;
			}
			else {
				rank[position] = ++cur_rank;
				cur_entry = entry[i].first;
			}
		}

		for(int i = 0; i < n; i++) {
			int position = entry[i].second;
			int next_position = (position + (1<<step))%n;
			entry[i].first = {rank[position], rank[next_position]};
		}
		step++;
	}

	vector<int> suffix_array(n);
	for(int i = 0; i < n; i++) {
		suffix_array[i] = entry[i].second;
	}

	return suffix_array;
}

int main() {
	string s = "abaab";

	for(auto i: ComputeSuffixArray(s)) {
		cout << i << ' '; 
	}
}
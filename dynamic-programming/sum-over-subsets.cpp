#include <bits/stdc++.h>

using namespace std;

vector<int> GetSumOverSubsetsDP(vector<int>& arr) {
	int n =  arr.size();

	vector<int> dp(1<<n, 0);

	for(int mask = 0; mask < (1<<n); mask++) {
		for(int i = 0; i < n; i++) {
			if(mask & (1<<i)) {
				dp[mask] += arr[i];
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int mask = 0; mask < (1<<n); mask++) {
			if(mask & (1<<i)) {
				dp[mask] += dp[mask ^ (1<<i)];
			}
		}
	}

	return dp;
}
int main() {
	vector<int> a = {1,2,3};
	cout << "Sum Over Subsets DP - " << endl;
	for(auto i: GetSumOverSubsetsDP(a)) {
		cout << i << " ";
	}
}
#include<bits/stdc++.h>
using namespace std;

const int p = 31;
const int m = 1e9 + 9;

long long rollingHash(string &s) {

	long long hashValue = 0;
	long long pPowI = 1;

	for(auto ch: s) {
		hashValue = (hashValue + (ch - 'a' + 1) * pPowI) % m;
		pPowI = (pPowI * p) % m;
	}

	return hashValue;
}

int main() {
	string s = "abcde";

	cout << rollingHash(s);
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int p = 31;
const int m = 1e9 + 9;

bool rabinCarp(string &text, string &pattern) {
	int textLen = text.size();
	int patternLen = pattern.size();

	vector<long long> prefixHash(textLen+1, 0);
	
	long long pPowI = 1;

	for(int i = 0; i < textLen; i++) {
		prefixHash[i+1] = (prefixHash[i] + (text[i] - 'a' + 1) * pPowI) % m;
		pPowI = (pPowI * p) % m;
	}

	pPowI = 1;
	long long patternHash = 0;

	for(int i = 0; i < patternLen; i++) {
		patternHash = (patternHash + (pattern[i] - 'a' + 1) * pPowI) % m;
		pPowI = (pPowI * p) % m;
	}

	pPowI = 1;
	for(int i = 0; i < textLen - patternLen+ 1; i++) {
		long long curHash = (prefixHash[i + patternLen] - prefixHash[i] + m) % m;
		if(curHash == (patternHash * pPowI) % m){
			return true;
		}
		pPowI = (pPowI * p) % m;
	}

	return false;
}

int main() {

	string text = "abaacdef";
	string pattern = "aac";

	cout << rabinCarp(text, pattern);

	return 0;
}
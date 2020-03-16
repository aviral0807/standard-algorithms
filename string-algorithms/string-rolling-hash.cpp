#include<bits/stdc++.h>
using namespace std;

const int kPrime = 31;
const int kMod = 1e9 + 9;

long long StringRollingHash(string &text) {

	long long hash_value = 0;
	long long p_pow_i = 1;

	for(auto ch: text) {
		hash_value = (hash_value + (ch - 'a' + 1) * p_pow_i) % kMod;
		p_pow_i = (p_pow_i * kPrime) % kMod;
	}

	return hash_value;
}

int main() {
	string text = "abcde";

	cout << StringRollingHash(text);

	return 0;
}
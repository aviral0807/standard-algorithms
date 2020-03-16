#include <bits/stdc++.h>

using namespace std;

const int kPrime = 31;
const int kMod = 1e9 + 9;

bool RabinCarp(string &text, string &pattern) {
	int text_len = text.size();
	int pattern_len = pattern.size();

	vector<long long> prefix_hash(text_len + 1, 0);
	
	long long prime_pow_i = 1;

	for(int i = 0; i < text_len; i++) {
		prefix_hash[i+1] = (prefix_hash[i] + (text[i] - 'a' + 1) * prime_pow_i) % kMod;
		prime_pow_i = (prime_pow_i * kPrime) % kMod;
	}

	prime_pow_i = 1;
	long long pattern_hash = 0;

	for(int i = 0; i < pattern_len; i++) {
		pattern_hash = (pattern_hash + (pattern[i] - 'a' + 1) * prime_pow_i) % kMod;
		prime_pow_i = (prime_pow_i * kPrime) % kMod;
	}

	prime_pow_i = 1;
	for(int i = 0; i < text_len - pattern_len + 1; i++) {
		long long cur_hash = (prefix_hash[i + pattern_len] - prefix_hash[i] + kMod) % kMod;
		if(cur_hash == (pattern_hash * prime_pow_i) % kMod) {
			return true;
		}
		prime_pow_i = (prime_pow_i * kPrime) % kMod;
	}

	return false;
}

int main() {

	string text = "abaacdef";
	string pattern = "aac";

	cout << RabinCarp(text, pattern);

	return 0;
}
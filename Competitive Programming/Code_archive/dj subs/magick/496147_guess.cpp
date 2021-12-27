// guess.cpp 23 Feb 19, 15:56:56 5 1 Judging completed in 8.458s on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int N, int K, string S) {
	string ans = "";
	for (int i = 0; i < K; i++) ans += S[N-1];
	return ans;
}
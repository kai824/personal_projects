// guess.cpp 23 Feb 19, 14:14:36 0 0.06 Judging completed in 23.668s on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int N, int K, string S) {
	string ans = "";
	for (int i = 0; i < K; i++) ans +=S[0]-'0';
	return ans;
}
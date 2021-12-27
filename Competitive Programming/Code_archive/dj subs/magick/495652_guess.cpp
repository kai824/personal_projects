// guess.cpp 23 Feb 19, 14:16:25 0 0.07 Judging completed in 27.959s on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int N, int K, string S) {
	string ans = "";
	for (int i = 0; i < K; i++) ans +=S[2]-'0';
	return ans;
}
// guess.cpp 23 Feb 19, 15:58:40 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int N, int K, string S) {
    for(int x=0;x<S.length();x++){
        if(S[x]=='?')return S[x-1];
    }
    srand(time(0));
	return rand()%10;
}
// guess.cpp 23 Feb 19, 16:01:52 0 1 Judging completed in 8.601s on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int N, int K, string S) {
    string ans=" ";
    for(int x=0;x<S.length();x++){
        if(S[x]=='?')ans[0]=S[x-1];
    }
    if(ans!=" ")return ans;
    srand(time(0));
	ans[0]=rand()%10+'0';return ans;
}
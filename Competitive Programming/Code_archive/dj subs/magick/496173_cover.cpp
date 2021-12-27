// cover.cpp 23 Feb 19, 16:01:52 0 1 Judging completed in 8.601s on AWS Oregon.
#include <bits/stdc++.h>
#include "cover.h"

using namespace std;

int cover(int N, int K, string S) {
    bool doable=false;
    for(int x=1;x<N;x++){
        if(S[x]==S[x-1]){
            return x;
            doable=true;
        }
    }
    if(doable==false)while(true){}
}
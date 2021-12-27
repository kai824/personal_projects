// ans.cpp 22 Jan 17, 20:23:00 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>=b);
}
long long int minTime(long long int N, long long int S, long long int H, long long int F[]){
    long long ans=0;
    sort(F,F+N,cmp);
    for(int x=0;x<N;x+=H){
        ans+=2*(F[x]);
    }
    return ans;
}

//number of minions(since f always has same number of stuff),
//number of floors, lift capacity, minion floors
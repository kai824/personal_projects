// sorting.cpp 27 Nov 17, 15:51:45 0 0.09 Judging completed in 7.822s on AWS Oregon.
#include "sorting.h"
#include<bits/stdc++.h>
using namespace std;

int findSwapPairs(int n,int s[],int m,int x[],int y[],int p[],int q[]){
    for(int i=0;i<m;i++){
        if(x[i]==y[i])continue;
        swap(s[x[i]],s[y[i]]);
    }
    pair<int,int> pp[n];
    int nex=0;
    for(int i=0;i<n;i++){
        pp[i].first=s[i];
        pp[i].second=i;
    }
    sort(pp,pp+n);
    for(int i=0;i<n;i++){
        //swap position i and position p[i].second
        if(i==pp[i].second)continue;
        p[nex]=min(i,pp[i].second);
        q[nex]=max(i,pp[i].second);
        if(s[p[nex]]<=s[q[nex]])continue;
        swap(s[ p[nex] ],s[ q[nex] ]);
        nex++;
    }
    return nex;
}
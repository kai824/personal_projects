// ans.cpp 7 Feb 17, 13:00:04 100 0.22 Judging completed in 7.096s on AWS Ireland.
#include "minimum.h"
#include<bits/stdc++.h>
using namespace std;

int findMin(int N, int A[]) {
    int ans=INT_MAX;
    for(int x=0;x<N;x++){
        ans=min(ans,A[x]);
    }
    return ans;
}
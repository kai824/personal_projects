// segmenttree.cpp 27 Apr 17, 22:00:15 0 1 Judging completed in 6.376s on AWS Ireland.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
int arr[1000],arr2[100005],sqrtn,n;
void init(int N){
    n=N;
    sqrtn=floor(sqrt(n));
    for(int x=0;x<sqrtn+5;x++){
        arr[x]=INT_MAX;
    }
}

void update(int P, int V) {
    arr2[P]=V;
    arr[P/sqrtn]=min(arr[P/sqrtn],V);
}

int query(int A, int B) {
    int ans=INT_MAX;
    while(A<=B){
        if((A-1)%sqrtn==0 && A+sqrtn-1<=B){
            ans=min(ans,arr[A/sqrtn]);
            A+=sqrtn;
        }else{
            ans=min(ans,arr2[A]);
            A++;
        }
    }
    return ans;
}
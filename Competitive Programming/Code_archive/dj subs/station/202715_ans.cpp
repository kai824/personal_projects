// ans.cpp 29 Mar 17, 21:26:52 0 0.06 Judging completed in 4.632s on AWS Ireland.
#include"station.h"
#include<bits/stdc++.h>
using namespace std;
int findMinDays(int n, int k, int lodge[]){
    if(k==1)return -1;
    int ans=0,current=0,pcurrent;
    while(true){
        pcurrent=current;
        for(int x=current+k-1;x>current;x--){
            if(x>=n)continue;
            current=x;
            ans++;
        }
        if(current+1==n)return ans;
        if(current==pcurrent){
            return -1;
        }
    }
}
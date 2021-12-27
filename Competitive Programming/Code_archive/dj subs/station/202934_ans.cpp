// ans.cpp 1 Apr 17, 21:51:53 100 0.06 Judging completed in 5.566s on AWS Ireland.
#include"station.h"
#include<bits/stdc++.h>
using namespace std;
int findMinDays(int n, int k, int lodge[]){
    int ans=0,current=0,pcurrent;
    while(true){
        pcurrent=current;
        for(int x=current+k;x>current;x--){
            if(x>=n)continue;
            if(lodge[x]==0)continue;
            current=x;
            ans++;
            break;
        }
        if(current+1==n)return ans;
        if(current==pcurrent){
            return -1;
        }
    }
}
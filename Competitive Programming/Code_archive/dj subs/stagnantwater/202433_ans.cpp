// ans.cpp 28 Mar 17, 09:21:20 100 0.3 Judging completed in 7.074s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,current,ans=0;
    cin>>n;
    int heights[n],ua[n],da[n];
    for(int x=0;x<n;x++){
        cin>>heights[x];
    }
    current=0;
    ua[0]=0;
    for(int x=1;x<n;x++){
        if(heights[x]<heights[x-1])current++;
        else if(heights[x]==heights[x-1]){
            ua[x]=ua[x-1];
            continue;
        }
        else current=0;
        ua[x]=current;
    }
    current=0;
    da[n-1]=0;
    for(int x=n-2;x>=0;x--){
        if(heights[x]<heights[x+1])current++;
        else current=0;
        da[x]=current;
    }
    for(int x=0;x<n;x++){
        if(ua[x]>0 && da[x]>0)ans++;
    }
    cout<<ans;
    return 0;
}
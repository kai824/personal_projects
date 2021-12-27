// ans.cpp 18 Oct 17, 23:06:10 0 0.14 Judging completed in 5.895s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,ans=0,xx;
    cin>>n>>k;
    int e[n],g[n];
    deque<pair<int,int> > lo;//leftovers
    //number, number of days left
    for(int x=0;x<n;x++){
        cin>>g[x];
    }
    for(int x=0;x<n;x++){
        cin>>e[x];
    }
    
    for(int x=0;x<n;x++){
        for(int y=0;x<lo.size();){
            lo[y].second--;
            if(lo[y].second<0)lo.pop_front();
            else y++;
        }
        lo.push_back(make_pair(g[x],k));
        for(int y=0;(y<lo.size() && e[x]>0);){
                if(lo[y].first<=e[x]){
                    e[x]-=lo[y].first;
                    ans+=lo[y].first;
                    lo.pop_front();
                }else{//lo[y].first>e[x]
                    lo[y].first-=e[x];
                    ans+=e[x];
                    e[x]=0;
                }
        }
    }
    cout<<ans;
    return 0;
}
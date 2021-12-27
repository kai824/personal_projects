// ans.cpp 4 Feb 20, 09:48:58 100 0.11 Judging completed in 4.181s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int last_seen[1000005];
int arr[200005],ans[200005],n;
int ft[200005];//counts the number of each occurence for last seen
pair<pair<int,int>,int> qrs[200005];

inline int ls(int x){
    return x & (-x);
}
void update(int p,int v){
    if(p==0)return;
    for(;p<=n;p+=ls(p))ft[p]+=v;
}
int query(int p){
    int ans=0;
    for(;p;p-=ls(p)){
        ans+=ft[p];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q,cur_it=0;
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
    }
    cin>>q;
    for(int x=0;x<q;x++){
        cin>>qrs[x].first.second>>qrs[x].first.first;
        qrs[x].second=x;
    }
    sort(qrs,qrs+q);
    for(int x=1;x<=n;x++){
        update(last_seen[arr[x]],-1);
        update(x,1);
        last_seen[arr[x]]=x;
        for(;qrs[cur_it].first.first<=x && cur_it<q;cur_it++){
            ans[qrs[cur_it].second]=query(qrs[cur_it].first.first)-query(qrs[cur_it].first.second-1);
        }
    }
    for(int x=0;x<q;x++){
        cout<<ans[x]<<'\n';
    }
    return 0;
}
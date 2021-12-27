// ans.cpp 18 Nov 17, 16:43:51 26 0.32 Judging completed in 5.529s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[50005],barr[50005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(arr,-1,sizeof(arr));
    memset(barr,-1,sizeof(barr));
    int n,e,a,b,c,q;
    cin>>n>>e;
    vector<pair<int,int> > adjmat[n+5];
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjmat[a].push_back(make_pair(b,c));
        adjmat[b].push_back(make_pair(a,c));
    }
    priority_queue<int,vector<int>,greater<int> > ds;
    ds.push(0);
    arr[0]=0;
    while(!ds.empty()){
        a=ds.top();
        ds.pop();
        for(int x=0;x<adjmat[a].size();x++){
            if(arr[adjmat[a][x].first ]==-1){
                ds.push(adjmat[a][x].first);
                arr[adjmat[a][x].first]=adjmat[a][x].second+arr[a];
            }
            if(arr[adjmat[a][x].first ]>adjmat[a][x].second+arr[a]){
                ds.push(adjmat[a][x].first);
                arr[adjmat[a][x].first]=adjmat[a][x].second+arr[a];
            }
        }
    }
    ds.push(n-1);
    barr[n-1]=0;
    while(!ds.empty()){
        a=ds.top();
        ds.pop();
        for(int x=0;x<adjmat[a].size();x++){
            if(barr[adjmat[a][x].first ]==-1){
                ds.push(adjmat[a][x].first);
                barr[adjmat[a][x].first]=adjmat[a][x].second+barr[a];
            }
            if(barr[adjmat[a][x].first ]>adjmat[a][x].second+barr[a]){
                ds.push(adjmat[a][x].first);
                barr[adjmat[a][x].first]=adjmat[a][x].second+barr[a];
            }
        }
    }
    cin>>q;
    for(int x=0;x<q;x++){int ans;
        cin>>a>>b;
        ans=min(arr[a]+barr[b],barr[a]+arr[b]);
        ans=min(barr[0],arr[n-1])-ans-1;
        if(ans<0)cout<<"-1\n";
        else cout<<ans<<'\n';
    }
    return 0;
}
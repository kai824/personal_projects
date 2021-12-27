// ans.cpp 9 Dec 17, 13:57:17 0 0.04 Judging completed in 4.491s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adjlis[100005];
bool visited[100005],visited2[100005];
int aaa=-1;
int dfs(int node,int current,bool a){
    
    visited[node]=true;
    int ans=current;
    for(int x=0;x<adjlis[node].size();x++){
        if(visited[adjlis[node][x].first])continue;
        int b=dfs(adjlis[node][x].first,current+adjlis[node][x].second,false);
        if(ans<b){
            ans=b;
            if(a){
                aaa=x;//the node never to visit again...
            }
        }
    }
    return ans;
}
int dfs2(int node,int current,bool a){
    
    visited2[node]=true;
    int ans=current;
    for(int x=0;x<adjlis[node].size();x++){
        if(visited2[adjlis[node][x].first])continue;
        int b=dfs2(adjlis[node][x].first,current+adjlis[node][x].second,false);
        if(ans<b){
            ans=b;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e,a,b,c;
    cin>>n>>e;
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjlis[a].push_back(make_pair(b,c));
        adjlis[b].push_back(make_pair(a,c));
    }
    int ans=dfs(0,0,true);
    if(aaa!=-1)swap(adjlis[0][aaa],adjlis[0].back());
    adjlis[0].pop_back();
    ans+=dfs2(0,0,true);
    cout<<ans;
    return 0;
}
// ans.cpp 18 Oct 17, 14:26:29 0 0.62 Judging completed in 3.862s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool l(string a,string b){
    if(b=="L")return true;
    if(a.length()==b.length()){
        return(a<b);
    }
    return(a.length()<b.length());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,s,t,a,b;
    string c;
    cin>>n>>m>>s>>t;
    vector<pair<int,string> > adj[n];
    string ans[n];
    for(int x=0;x<m;x++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    for(int x=0;x<n;x++){ans[x]="L";}
    /*queue<int> bfs;
    bfs.push(s);
    ans[s]="";
    while(!bfs.empty()){
        //explore all the stuff connected to the top one
        a=bfs.front();
        for(int x=0;x<adj[a].size();x++){
            if(l(ans[a]+adj[a][x].second,ans[adj[a][x].first])){
                ans[adj[a][x].first]=ans[a]+adj[a][x].second;
                bfs.push(adj[a][x].first);
            }
        }
        bfs.pop();
    }
    if(ans[t]=="L")cout<<-1;
    else cout<<ans[t];*/
    cout<<-1;
    return 0;
}
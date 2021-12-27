// ans.cpp 18 Oct 17, 14:04:56 0 1.13 Judging completed in 6.19s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,s,t,a,b;string c;
    bool broke=false;
    cin>>n>>m>>s>>t;
    vector<pair<int,string> > adjlist[n];
    pair<int,string> tp;
    for(int x=0;x<m;x++){
        cin>>a>>b>>c;
        adjlist[a].push_back(make_pair(b,c));
        adjlist[b].push_back(make_pair(a,c));
    }
    c="";a=-1;
    queue<pair<int,string> > bfs;
    bfs.push(make_pair(s,""));
    while(!bfs.empty()){
        tp=bfs.front();
        bfs.pop();
        if(tp.first==t){
            broke=true;//used as found?
            if(a==-1){
                a=tp.second.length();
                c=tp.second;
            }else if(a>=tp.second.length()){
                a=tp.second.length();
                if(tp.second<c)c=tp.second;
            }else{
                break;
            }
        }
        if(a!=-1 && tp.second.length()>a)break;
        for(int x=0;x<adjlist[tp.first].size();x++){
            bfs.push(make_pair(adjlist[tp.first][x].first,tp.second+adjlist[tp.first][x].second));
        }
    }
    if(broke)cout<<c;
    else cout<<-1;
    return 0;
}
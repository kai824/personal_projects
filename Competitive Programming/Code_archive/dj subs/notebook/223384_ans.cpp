// ans.cpp 18 Oct 17, 14:38:34 0 0.92 Judging completed in 5.199s on AWS Oregon.
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
    bool bit;
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
    vector<int> bfs,bfs2;
    bfs.push_back(s);
    ans[s]="";
    bit=true;
    while(bfs.size()+bfs2.size()){
        //explore all the stuff connected to the top one
        /*a=bfs.front();
        for(int x=0;x<adj[a].size();x++){
            if(l(ans[a]+adj[a][x].second,ans[adj[a][x].first])){
                ans[adj[a][x].first]=ans[a]+adj[a][x].second;
                bfs.push(adj[a][x].first);
            }
        }
        bfs.pop();*/
        if(bit){
        	bfs2.clear();
        	for(int y=0;y<bfs.size();y++){
        		a=bfs[y];
        		for(int x=0;x<adj[a].size();x++){
        			if(l(ans[a]+adj[a][x].second,ans[adj[a][x].first])){
        				ans[adj[a][x].first]=ans[a]+adj[a][x].second;
        				bfs2.push_back(adj[a][x].first);
        			}
        		}
        	}
        }else{
        	bfs.clear();
        	for(int y=0;y<bfs2.size();y++){
        		a=bfs2[y];
        		for(int x=0;x<adj[a].size();x++){
        			if(l(ans[a]+adj[a][x].second,ans[adj[a][x].first])){
        				ans[adj[a][x].first]=ans[a]+adj[a][x].second;
        				bfs.push_back(adj[a][x].first);
        			}
        		}
        	}
        }
        bit=!bit;
    }
    if(ans[t]=="L")cout<<-1;
    else cout<<ans[t];
    return 0;
}
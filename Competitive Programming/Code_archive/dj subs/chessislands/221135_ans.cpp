// ans.cpp 29 Sep 17, 07:23:45 100 0.14 Judging completed in 7.626s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,e,bb,ww,a,b,ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>e;
    int areas[n];
    bool painted[n],colours[n];
    vector<int> adjlist[n+5];
    for(int x=0;x<n;x++){
        cin>>areas[x];painted[x]=false;
    }
    for(int x=0;x<e;x++){
        cin>>b>>a;
        a--;b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    vector<pair<int,bool> >bfs;
    for(int x=0;x<n;x++){
        if(painted[x])continue;
        bfs.push_back(make_pair(x,true));
        bb=0;ww=0;
        while(!bfs.empty()){
            a=bfs.back().first;b=bfs.back().second;
            bfs.pop_back();
            if(painted[a])continue;
            if(b){
            	bb+=areas[a];
            }else{
            	ww+=areas[a];
            }
            painted[a]=true;
            colours[a]=b;
            for(int y=0;y<adjlist[a].size();y++){
                if(painted[adjlist[a][y]])continue;
                bfs.push_back(make_pair(adjlist[a][y] ,!b));
            }
        }
        ans+=min(bb,ww);
    }
    cout<<ans;
    return 0;
}
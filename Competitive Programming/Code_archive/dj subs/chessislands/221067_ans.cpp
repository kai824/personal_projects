// ans.cpp 28 Sep 17, 10:30:57 0 0.39 Judging completed in 7.291s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,e,ans,bb,ww,a,b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>e;
    int areas[n];
    bool painted[n];
    vector<int> adjlist[e+5];
    for(int x=0;x<n;x++){
        cin>>areas[x];painted[x]=false;
    }
    for(int x=0;x<e;x++){
        cin>>b>>a;
        a--;b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    queue<pair<int,bool> >bfs;
    for(int x=0;x<n;x++){
        if(painted[x])continue;
        bb=0;ww=0;
        bfs.push(make_pair(x,true));
        painted[x]=true;
        while(!bfs.empty()){
            a=bfs.front().first;
            painted[a]=true;
            if(bfs.front().second==true)bb+=areas[a];
            else ww+=areas[a];
            for(int x=0;x<adjlist[a].size();x++){
                if(painted[adjlist[a][x]])continue;
                bfs.push(make_pair(adjlist[a][x] ,!bfs.front().second));
            }
            bfs.pop();
        }
        ans+=min(bb,ww);
    }
    cout<<ans;
    return 0;
}
// ans.cpp 28 Sep 17, 22:09:17 40 0.29 Judging completed in 5.955s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,e,bb,ww,a,b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>e;
    int areas[n];
    bool painted[n],colours[n];
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
        bfs.push(make_pair(x,true));
        painted[x]=true;
        while(!bfs.empty()){
            a=bfs.front().first;
            painted[a]=true;
            colours[a]=bfs.front().second;
            for(int y=0;y<adjlist[a].size();y++){
                if(painted[adjlist[a][y]])continue;
                bfs.push(make_pair(adjlist[a][y] ,!bfs.front().second));
            }
            bfs.pop();
        }
    }
    for(int x=0;x<n;x++){
    	if(colours[x])bb+=areas[x];
    	else ww+=areas[x];
    }
    cout<<min(bb,ww);
    return 0;
}
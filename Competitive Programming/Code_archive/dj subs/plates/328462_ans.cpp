// ans.cpp 21 Feb 18, 08:33:07 0 0 Judging completed in 5.502s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int vcost[1005],hcost[1005];
vector<int> vadjlist[1005],hadjlist[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string mp[1005];
    int h,w;
    cin>>h>>w;
    for(int x=0;x<1005;x++){
        vcost[x]=1e9;hcost[x]=1e9;
    }
    for(int x=0;x<h;x++){
        cin>>mp[x];
        for(int y=0;y<w;y++){
            if(mp[x][y]=='#'){
                hadjlist[y].push_back(x);
                vadjlist[x].push_back(y);
            }
        }
    }
    deque<pair<bool,int> >bfs;//0 for bool means vertical(x,num)
    //1 for bool means horizontal(num,y)
    bfs.push_back(make_pair(false,0));vcost[0]=0;
    bfs.push_back(make_pair(true,0));hcost[0]=0;
    while(bfs.size()>0){
        if(bfs[0].first){//horizontal
            for(int x=0;x<hadjlist[bfs[0].second].size();x++){
                if(hcost[bfs[0].second]+1<vcost[hadjlist[bfs[0].second][x]]){
                    bfs.push_back(make_pair(false,hadjlist[bfs[0].second][x]));
                    vcost[hadjlist[bfs[0].second][x]]=hcost[bfs[0].second]+1;
                }
            }
        }else{
            for(int x=0;x<vadjlist[bfs[0].second].size();x++){
                if(vcost[bfs[0].second]+1<hcost[vadjlist[bfs[0].second][x]]){
                    bfs.push_back(make_pair(true,vadjlist[bfs[0].second][x]));
                    hcost[vadjlist[bfs[0].second][x]]=vcost[bfs[0].second]+1;
                }
            }
        }
        bfs.pop_front();
    }h--;w--;
    if(min(vcost[h],hcost[w])==1e9){
        cout<<"-1";
    }else{
        cout<<min(vcost[h],hcost[w]);
    }
    return 0;
}
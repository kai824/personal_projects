// ans.cpp 11 Feb 17, 17:14:45 0 0.01 Judging completed in 8.692s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    map<string,int>f,h;
    int n,m,q,c,d,e;
    cin>>n>>m>>q;
    vector<pair<pair<int,int>,pair<int,pair<string,array<bool,4> > > > > b[n];
    queue<int>bb;
    array<bool,4> g;
    int aa[n];
    cin>>f["ground"];
    cin>>f["water"];
    cin>>f["grass"];
    cin>>f["forest"];
    h["ground"]=0;
    h["water"]=1;
    h["grass"]=2;
    h["forest"]=3;
    for(int x=0;x<m;x++){
        cin>>c>>d>>e>>a;
        b[d-1].push_back(make_pair(make_pair(d-1,c-1),make_pair(e,make_pair(a,g))));
        b[c-1].push_back(make_pair(make_pair(c-1,d-1),make_pair(e,make_pair(a,g))));
    }
    for(int x=0;x<q;x++){
        fill_n(aa,n,1000000005);
        cin>>c>>d;
        c--;
        d--;
        aa[c]=0;
        bb.push(c-1);
        while(!bb.empty()){
            for(int x=0;x<b[bb.front()].size();x++){
                if(!b[bb.front()][x].second.second.second[h[b[bb.front()][x].second.second.first]]){
                    e=f[b[bb.front()][x].second.second.first];
                    b[bb.front()][x].second.second.second[h[b[bb.front()][x].second.second.first]]=true;
                }else e=0;
                if(b[bb.front()][x].second.first+aa[bb.front()]+e<aa[b[bb.front()][x].first.second]){
                    bb.push(b[bb.front()][x].first.second);
                    aa[b[bb.front()][x].first.second]=b[bb.front()][x].second.first+aa[bb.front()]+e;
                }else if(b[bb.front()][x].second.first+aa[bb.front()]+e==aa[b[bb.front()][x].first.second]){
                    bb.push(b[bb.front()][x].first.second);
                }
            }
            bb.pop();
        }
        cout<<aa[d]<<endl;
    }
    return 0;
}
// ans.cpp 7 Mar 20, 10:13:52 100 0.03 Judging completed in 3.566s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

pair<pii,pii> children[100005];
pii parent[100005];//parent, weight
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,b,c,d;
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>a>>b>>c>>d;
        children[x]=mp(mp(a,b),mp(c,d));
        parent[a]=mp(x,b);
        parent[c]=mp(x,d);
    }
    cin>>a;
    d=1;
    while(a!=1){
        b=parent[a].first;
        if(a==children[b].first.first){
            if(d>children[b].first.second){
                cout<<"-1\n";return 0;
            }
            d+=max(0,children[b].second.second-(children[b].first.second-d+1));
        }else{
            if(d>children[b].second.second){
                cout<<"-1\n";return 0;
            }
            d+=max(0,children[b].first.second-(children[b].second.second-d) );
        }
        a=b;
    }
    cout<<d<<'\n';
    return 0;
}
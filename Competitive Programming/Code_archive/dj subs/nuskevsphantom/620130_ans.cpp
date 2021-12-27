// ans.cpp 2 Dec 19, 10:40:06 100 0.19 Judging completed in 3.998s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

bool mp[2005][2005];
int ps[2005][2005];
int hs[2005][2005];
int vs[2005][2005];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q,cur,cur2;
    string a;
    cin>>n>>m>>q;
    for(int x=1;x<=n;x++){
        cin>>a;
        cur=0;
        for(int y=0;y<m;y++){
            cur+=a[y]-'0';
            mp[x][y+1]=a[y]-'0';
            ps[x][y+1]=cur+ps[x-1][y+1];
        }
    }
    for(int x=1;x<=n;x++){
        cur=cur2=0;
        for(int y=1;y<=m;y++){
            if(mp[x][y]&&mp[x-1][y]){
                vs[x][y]=1;
            }
            cur+=vs[x][y];
            vs[x][y]=vs[x-1][y]+cur;
            if(mp[x][y]&&mp[x][y-1]){
                hs[x][y]=1;
            }
            cur2+=hs[x][y];
            hs[x][y]=hs[x-1][y]+cur2;
        }
    }
    int x1,x2,y1,y2;
    for(int x=0;x<q;x++){
        cin>>x1>>y1>>x2>>y2;
        x1--;y1--;
        cout<<(ps[x2][y2]-ps[x1][y2]-ps[x2][y1]+ps[x1][y1])-( (vs[x2][y2]-vs[x1+1][y2]-vs[x2][y1]+vs[x1+1][y1])+(hs[x2][y2]-hs[x1][y2]-hs[x2][y1+1]+hs[x1][y1+1]) );
        cout<<'\n';
    }
    return 0;
}
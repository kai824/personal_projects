// ans.cpp 6 Feb 20, 18:49:37 30 0.13 Judging completed in 3.797s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int ps[1100][1100],arr[1100][1100];
inline int sum(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return ps[x2][y2]-ps[x2][y1]-ps[x2][y2]+ps[x1][y1];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a,b,lo,hi,mid,ans=0;
    cin>>n>>k;
     for(int x=0;x<=n;x++){
        for(int y=0;y<=n;y++){
            ps[x][y]=arr[x][y]=0;
        }
    }
    for(int x=0;x<k;x++){
        cin>>a>>b;
        ps[a+1][b+1]=arr[a+1][b+1]=1;
    }
    for(int x=1;x<=n;x++){
        a=0;
        for(int y=1;y<=n;y++){
            a+=ps[x][y];
            ps[x][y]=a+ps[x-1][y];
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            if(arr[x][y]==1)continue;
            lo=0;
            hi=min(x,y);
            while(lo<hi){
                mid=hi-(hi-lo)/2;
                if(sum(x-mid,y-mid,x,y)==0){
                    lo=mid;
                }else hi=mid-1;
            }
            ans=max(ans,lo);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
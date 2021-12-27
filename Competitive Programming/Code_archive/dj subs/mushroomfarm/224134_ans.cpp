// ans.cpp 19 Oct 17, 15:35:19 47 0.74 Judging completed in 6.101s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int ps[2005][2005],current,ans;//r,c
//      ans counts the number of solutions we already have
int query(int xx, int yy, int xx2, int yy2){
	return(ps[xx2][yy2]+ps[xx-1][yy-1]-ps[xx2][yy-1]-ps[xx-1][yy2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,k,lo,hi,mid;
    cin>>r>>c>>k;
    for(int x=1;x<=r;x++){
        current=0;
        for(int y=1;y<=c;y++){
            cin>>ps[x][y];
            current+=ps[x][y];
            ps[x][y]=ps[x-1][y]+current;
        }
    }
    for(int x=1;x<=r;x++){
        for(int y=1;y<=c;y++){
            lo=0;hi=min(r-x,c-y);
            if(query(x,y,x+hi,y+hi)<k)continue;
            while(lo<hi){//find the smallest size that can make it
                mid=(lo+hi)/2;
                if(query(x,y,x+mid,y+mid)<k){
                    lo=mid+1;
                }else{
                    hi=mid;
                }
            }
            ans+=min(r-x,c-y)-lo+1;
        }
    }
    cout<<ans;
    return 0;
}
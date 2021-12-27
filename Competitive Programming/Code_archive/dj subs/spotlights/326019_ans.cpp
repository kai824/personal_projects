// ans.cpp 14 Feb 18, 08:19:17 0 2.03 Judging completed in 13.866s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,n,current,maxi=INT_MAX,maxx,maxy;
    cin>>r>>c>>n;
    int xx[n],yy[n],hh[n];
    for(int x=0;x<n;x++){
        cin>>yy[x]>>xx[x]>>hh[x];
    }
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            current=-1;
            for(int i=0;i<n;i++){
                current=max(current,hh[i]+abs(y-yy[i])+abs(x-xx[i]));
            }
            if(current<maxi){
                maxi=current;
                maxx=x;
                maxy=y;
            }
        }
    }
    cout<<maxx<<' '<<maxy<<' '<<maxi;
    return 0;
}
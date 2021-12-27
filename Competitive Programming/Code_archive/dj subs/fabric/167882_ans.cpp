// ans.cpp 7 Dec 16, 16:02:12 0 1 Judging completed in 6.103s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,ans=0;
    bool broke;
    cin>>n>>m>>k;
    char fabric[n][m];
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cin>>fabric[x][y];
        }
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            for(int a=0;a<m-y;a++){
                if(fabric[x][y+a]=='1')break;
                if(a+1*(n-x)<k)continue;
                ans++;
                for(int b=1;b<n-x;b++){
                    if((a+1)*(b+1)<k)continue;
                    broke=false;
                    for(int c=y;c<y+a+1;c++){
                        if(fabric[b+x][c]=='1'){
                            broke=true;
                            break;
                        }
                    }
                    if(broke)break;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
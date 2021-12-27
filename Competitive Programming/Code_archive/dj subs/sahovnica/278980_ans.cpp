// ans.cpp 5 Dec 17, 11:46:38 0 0 Judging completed in 4.009s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,a,b;cin>>r>>c>>a>>b;
    bool v;
    for(int x=0;x<r;x++){
        for(int y=0;y<a;y++){
            v=!(x&1);
            for(int z=0;z<c;z++){
                for(int i=0;i<b;i++){
                    if(v)cout<<'x';
                    else cout<<'.';
                }v=!v;
            }
            cout<<'\n';
        }
    }
    return 0;
}
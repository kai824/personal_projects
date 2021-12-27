// ans.cpp 9 Mar 20, 15:25:31 100 0.51 Judging completed in 5.131s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cnts[256][256];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int q,xx,ans=0;
    string s;
    cin>>q;
    while(q--){
        cin>>s>>xx;
        if(s=="add"){
            for(int i=0;i<256;i++){
                if( (i&(xx%256)) ==(xx%256) )cnts[xx/256][i]++;
            }
        }else if(s=="cnt"){
            ans=0;
            for(int i=0;i<256;i++){
                if( (i&(xx/256)) ==i )ans+=cnts[i][xx%256];
            }
            cout<<ans<<'\n';
        }else{
            for(int i=0;i<256;i++){
                if( (i&(xx%256)) ==(xx%256) )cnts[xx/256][i]--;
            }
        }
    }
    return 0;
}
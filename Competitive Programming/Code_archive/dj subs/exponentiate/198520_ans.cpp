// ans.cpp 11 Mar 17, 21:33:27 100 0.35 Judging completed in 4.679s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int a,b,m,n;
    long long int ans,current;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a>>b>>m;
        ans=1;
        for(int y=19;(y>=0 && b>0);y--){
            current=a;
            if(pow(2,y)>b)continue;
            for(int z=0;z<y;z++){
                current=current*current;
                current=current%m;
            }
            current=current%m;
            ans*=current;
            ans=ans%m;
            b-=pow(2,y);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
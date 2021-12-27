// ans.cpp 11 Mar 17, 21:32:42 100 0.52 Judging completed in 4.724s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
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
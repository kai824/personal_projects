// ans.cpp 16 Feb 19, 18:22:53 100 0 Judging completed in 4.394s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll pways[2505],nways[2505];//since xi<=50, n<=50
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a,coefficient=0,ans=0;
    long long i;
    cin>>n>>a;
    pways[0]=1;nways[0]=1;
    for(int x=0;x<n;x++){
        cin>>i;
        i-=a;
        if(i<0){
            i=-i;
            for(int j=2504;j>=i;j--){
                nways[j]+=nways[j-i];
            }
        }else if(i>0){
            for(int j=2504;j>=i;j--){
                pways[j]+=pways[j-i];
            }
        }else{
            coefficient++;
            //since adding that number to any combi will make average same
        }
    }
    for(int x=1;x<2505;x++){
		//cout<<pways[x]<<' '<<nways[x]<<'\n';
        ans+=pways[x]*nways[x];
    }
    if(ans*(1LL<<coefficient)+(1LL<<coefficient)-1ll<0){
        while(true){};
    }
    cout<<ans*(1LL<<coefficient)+(1LL<<coefficient)-1ll;
    return 0;
}
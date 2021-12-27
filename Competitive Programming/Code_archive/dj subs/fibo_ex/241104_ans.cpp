// ans.cpp 4 Nov 17, 14:22:24 45 1 Judging completed in 5.343s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
struct matrix{
    ll a[2][2];
};
ll ipow(ll a,ll b){
    ll ans=1;
    for(ll x=0;x<b;x++){
        ans*=a;
    }
    return ans;
}
matrix ansx;
matrix multiply(matrix a, matrix b){//remember to mod m...
    ansx.a[0][0]=((a.a[0][0]*b.a[0][0])%m+(a.a[0][1]*b.a[1][0])%m)%m;
    //x  -
    //-  -
    ansx.a[0][1]=((a.a[0][0]*b.a[0][1])%m+(a.a[0][1]*b.a[1][1])%m)%m;
    //-  x
    //-  -
    ansx.a[1][0]=((a.a[1][0]*b.a[0][0])%m+(a.a[1][1]*b.a[1][0])%m)%m;
    //-  -
    //x  -
    ansx.a[1][1]=((a.a[1][0]*b.a[0][1])%m+(a.a[1][1]*b.a[1][1])%m)%m;
    //-  -
    //-  x
    return ansx;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll tc,n,p;
    matrix a,current,ans,reset;
    reset.a[0][0]=1;reset.a[0][1]=1;reset.a[1][0]=1;reset.a[1][1]=0;
    cin>>tc;
    while(tc--){
        ans=reset;
        a=reset;
        cin>>n>>m;//calculate the matrix raised to the power of n...
        for(int x=30;x>=0;x--){
            p=ipow(2,x);
            if(p>n)continue;
            current=a;
            for(int y=0;y<x;y++){
                current=multiply(current,current);
            }
            ans=multiply(ans,current);
            n-=p;
        }
        cout<<ans.a[1][1]<<'\n';
    }
    return 0;
}
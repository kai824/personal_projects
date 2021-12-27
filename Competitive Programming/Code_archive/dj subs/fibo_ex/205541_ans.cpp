// ans.cpp 30 Apr 17, 16:55:48 45 1 Judging completed in 3.745s on AWS Oregon.
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
matrix multiply(matrix a, matrix b){//remember to mod m...
    matrix ans;
    ans.a[0][0]=((a.a[0][0]*b.a[0][0])%m+(a.a[0][1]*b.a[1][0])%m)%m;
    //x  -
    //-  -
    ans.a[0][1]=((a.a[0][0]*b.a[0][1])%m+(a.a[0][1]*b.a[1][1])%m)%m;
    //-  x
    //-  -
    ans.a[1][0]=((a.a[1][0]*b.a[0][0])%m+(a.a[1][1]*b.a[1][0])%m)%m;
    //-  -
    //x  -
    ans.a[1][1]=((a.a[1][0]*b.a[0][1])%m+(a.a[1][1]*b.a[1][1])%m)%m;
    //-  -
    //-  x
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll tc,n;
    matrix a,current,ans,reset;
    reset.a[0][0]=1;reset.a[0][1]=1;reset.a[1][0]=1;reset.a[1][1]=0;
    cin>>tc;
    while(tc--){
        ans=reset;
        a=reset;
        cin>>n>>m;//calculate the matrix raised to the power of n...
        for(int x=30;x>=0;x--){
            if(ipow(2,x)>n)continue;
            current=a;
            for(int y=0;y<x;y++){
                current=multiply(current,current);
            }
            ans=multiply(ans,current);
            n-=ipow(2,x);
        }
        cout<<ans.a[1][1]<<'\n';
    }
    return 0;
}
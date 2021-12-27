// ans.cpp 27 Nov 17, 15:34:19 100 0.67 Judging completed in 3.475s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
struct matrix{
    ll a[2][2];
};
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

matrix reset,matrix_one;

ll ipow(ll exponent){
	matrix base=reset;
	matrix result=matrix_one;                        
    while (exponent){
        if (exponent%2==1)result=multiply(result,base);
        base=multiply(base,base);
        exponent >>= 1;
    }
    return result.a[1][1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc,n,p;
    matrix a,current,ans;
    reset.a[0][0]=1;reset.a[0][1]=1;reset.a[1][0]=1;reset.a[1][1]=0;
    matrix_one.a[0][0]=1;
    matrix_one.a[0][1]=0;
    matrix_one.a[1][0]=0;
    matrix_one.a[1][1]=1;
    cin>>tc;
    while(tc--){
        ans=reset;
        a=reset;
        cin>>n>>m;
        cout<<ipow(n+1)<<'\n';
    }
}
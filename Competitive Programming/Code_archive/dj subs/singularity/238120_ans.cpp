// ans.cpp 31 Oct 17, 18:01:35 44 1.5 Judging completed in 5.641s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long arr[1000005],n;
long long st[23][1000005];//sparse table...
long long pow2[23];

long long gcd2(long long a, long long b){
    a%=b;
    if (a==0) return b;
    else return gcd2(b,a);
}
long long gcd(long long a,long long b){
    if(a<b)swap(a,b);
    return gcd2(a,b);
}
long long f_log2(long long a){
    long long ans=0;
    while(a>=2){
        a/=2;
        ans++;
    }
    return ans;
}

void init(){
    long long ppow=2;
    for(long long x=0;x<n;x++){
        st[0][x]=arr[x];
    }
    for(long long x=1;ppow<=n;x++){
        for(long long y=0;y+ppow-1<n;y++){
            st[x][y]=gcd(st[x-1][y],st[x-1][y+(ppow/2)]);
        }
        ppow*=2;//stores 2^x
    }
}
long long query(long long a, long long b) {
    long long k=f_log2(b-a+1);
    return gcd(st[k][a],st[k][b+1-pow2[k]]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    pow2[0]=1;//2^0 = 1
    for(int x=1;x<23;x++){
        pow2[x]=pow2[x-1]*2;
    }
    init();
    long long lo,hi,mid,ans=0;
    for(long long x=0;x<n;x++){
        lo=x;hi=n-1;
        while(lo<hi){//find smalong longest range where gcd!=1...
            mid=lo+hi;
            mid-=(lo+hi)/2;
            if(query(x,mid)!=1){//mid is too smalong long...
                lo=mid;
            }else{//the gcd of the stuff is 1
                hi=mid-1;
            }
        }
        ans+=n-1-lo;
        if(query(x,lo)==1)ans++;
    }
    cout<<ans;
    return 0;
}
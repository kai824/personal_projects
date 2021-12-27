// ans.cpp 24 Feb 18, 00:10:14 100 2.72 Judging completed in 9.166s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>ss;
vector<pair<int,int> > stuff;
bool sieve[32000];
long long p(long long x,long long y,long long m){
    if(y==0)return 1;
    if(y==1)return x%m;
	unsigned long long ans=1;
	while (y>0){
		if (y%2==1){
			ans=(ans*x)%m;
		}
		y/=2;
		x=(x*x)%m;
	}
	return ans%m;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,aaa,ans=1,i,u;
    int cnt;
    for(int x=2;x<32000;x++){
        if(sieve[x]==false){
            stuff.push_back(make_pair(x,0));
            u=x*2;
            while(u<32000){
                sieve[u]=true;
                u+=x;
            }
        }
    }
    cin>>n;
    for (i=0;i<n;i++){
        cin>>aaa;aaa++;
        for(int x=0;x<stuff.size();x++){
            if(aaa%stuff[x].first!=0)continue;
            cnt=0;
            while(aaa%stuff[x].first==0){
                cnt++;
                aaa/=stuff[x].first;
            }
            stuff[x].second=max(stuff[x].second,cnt);
        }
        if(aaa!=1)ss.push_back(aaa);
    }
    for(i=0;i<stuff.size();i++){
      ans*=p(stuff[i].first,stuff[i].second,1000000007);
      ans%=1000000007;
    }
    sort(ss.begin(),ss.end());
    for(int x=0;x<ss.size();x++){
        if(x==0 || ss[x]!=ss[x-1]){
            ans*=ss[x];
            ans%=1000000007;
        }
    }
    ans--;
    if(ans<0)ans+=1000000007;
    cout<<ans;
}
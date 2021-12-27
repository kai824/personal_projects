// ans.cpp 23 Feb 18, 22:22:32 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnts[100005],cnt;
vector<ll>ss;
void update(ll base,ll exponent){
    if(base>100000)ss.push_back(base);
    else{
        cnts[base]=max(cnts[base],exponent);
    }
}
void primeFactors(ll n)
{
    // Print the number of 2s that divide n
    cnt=0;
    while (n%2 == 0)
    {
        cnt++;
        n = n/2;
    }
    update(2,cnt);
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i*i <= n; i = i+2)
    {
        // While i divides n, print i and divide n
        cnt=0;
        while (n%i == 0)
        {
            cnt++;
            n = n/i;
        }
        update(i,cnt);
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        update(n,1);
}

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
    ll n,x,ans=1,i;
    cin>>n;
    for (i=0;i<n;i++){
      cin>>x;
      x++;
      sum=0;
      prime(x,2);
    }
    /*for(i=2;i<100000;i++){
      ans*=p(i,cnts[i],1000000007);
      ans%=1000000007;
    }
    sort(ss.begin(),ss.end());
    for(int x=0;x<ss.size();x++){
        if(x==0 || ss[x]!=ss[x-1]){
            ans*=ss[x];
            ans%=1000000007;
        }
    }*/
    ans--;
    if(ans<0)ans+=1000000007;
    cout<<ans;
}
// ans.cpp 22 Feb 18, 10:24:46 76 0.02 Judging completed in 4.977s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnts[100005],sum;
ll prime(ll n,ll x)
{	
  if (n%x==0){
    sum++;
    if (n/x<=1){
    if (sum!=0){
      //cout<<x<<"^"<<sum<<endl;
      cnts[x]=max(cnts[x],sum);
    }
    return 0;
    }
    return prime(n/x,x);
  }
  else {
    if (sum!=0){
      //cout<<x<<"^"<<sum<<endl;
      cnts[x]=max(cnts[x],sum);
    }
    sum=0;
    if (x==2){
    	return prime(n,x+1);
    }
    else if (x>sqrt(n)){
    	//cout<<n<<"^1"<<endl;
    	cnts[n]=max(cnts[n],1LL);
    }
    else return prime(n,x+2);
  }
  

}

long long p(long long x,long long y,long long m){
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
    for(i=2;i<100000;i++){
      ans*=p(i,cnts[i],1000000007);
      ans%=1000000007;
    }
    ans--;
    if(ans<0)ans+=1000000007;
    cout<<ans;
}
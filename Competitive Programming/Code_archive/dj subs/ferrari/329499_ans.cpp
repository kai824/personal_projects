// ans.cpp 23 Feb 18, 21:55:08 76 3 Judging completed in 7.947s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnts[10000005],sum;
ll extra=1;
ll prime(ll n,ll x)
{	
  if (n%x==0){
    sum++;
    if (n/x<=1){
    if (sum!=0){
      //cout<<x<<"^"<<sum<<endl;
      if(x<10000000)cnts[x]=max(cnts[x],sum);
      else{
          extra*=x;
          extra%=1000000007;
      }
    }
    return 0;
    }
    return prime(n/x,x);
  }
  else {
    if (sum!=0){
      //cout<<x<<"^"<<sum<<endl;
      if(x<10000000)cnts[x]=max(cnts[x],sum);
      else{
          extra*=x;
          extra%=1000000007;
      }
    }
    sum=0;
    if (x==2){
    	return prime(n,x+1);
    }
    else if (x>sqrt(n)){
    	//cout<<n<<"^1"<<endl;
    	if(n<10000000)cnts[n]=max(cnts[n],1LL);
    	else{
    	    extra*=n;
    	    extra%=1000000007;
    	}
    }
    else return prime(n,x+2);
  }
  

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
    for(i=2;i<10000000;i++){
      ans*=p(i,cnts[i],1000000007);
      ans%=1000000007;
    }
    ans*=extra;
    ans%=1000000007;
    ans--;
    if(ans<0)ans+=1000000007;
    cout<<ans;
}
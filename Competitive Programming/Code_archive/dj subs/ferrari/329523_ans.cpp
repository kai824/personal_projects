// ans.cpp 23 Feb 18, 22:55:56 76 3 Judging completed in 7.609s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnts[100005],sum;
ll pows[50001];
bool st[10000005];
vector<ll>ss;
ll prime(ll n,ll x)
{	
    if(x<=50000 && n%pows[x]==0){
        sum+=2;
        if(n/pows[x]<2){
            if(x<100000)cnts[x]=max(cnts[x],sum);
            else{
                ss.push_back(x);
            }
            return 0;
        }
        return prime(n/pows[x],x);
  }else if (n%x==0){
    sum++;
    if (n/x<=1){
    if (sum!=0){
        if(x<100000)cnts[x]=max(cnts[x],sum);
        else{
            ss.push_back(x);
        }
    }
    return 0;
    }
    return prime(n/x,x);
  }
  else {
    if (sum!=0){
        //cout<<x<<"^"<<sum<<endl;
        if(x<100000)cnts[x]=max(cnts[x],sum);
        else{
            ss.push_back(x);
        }
    }
    sum=0;
    if (x==2){
    	return prime(n,x+1);
    }
    else if (x*x>n){
    	//cout<<n<<"^1"<<endl;
    	if(n<100000)cnts[n]=max(cnts[n],1LL);
        else{
            ss.push_back(n);
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
    for(int x=1;x<=50000;x++){
        pows[x]=x*x;
    }
    for (i=0;i<n;i++){
      cin>>x;
      x++;
      sum=0;
      if(x<10000005){
          if(st[x])continue;
          else st[x]=true;
      }
      prime(x,2);
    }
    for(i=2;i<100000;i++){
      ans*=p(i,cnts[i],1000000007);
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
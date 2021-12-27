// ans.cpp 30 Mar 19, 22:19:31 0 0 Compilation failed on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag=false;
inline char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline ll get()
{
    ll ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}
ll dp[1000005];//dp i stores answer if it can contain all the stuff from the back to the ith height
bool cmp(pair<int,int> a,pair<int,int> b){
	return (a.first>b.first);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,q,lo,hi,mid,ans,s,e,l,a;
	n=get();q=get();
	pair<int,int> arr[n];//height, iterator
	for(int x=0;x<n;x++){
		arr[x].first=get();arr[x].second=x;
	}
	sort(arr,arr+n,cmp);//descending order
	ans=(n*(n-1))/2 + n;
	set<int> ss;//stores iterators
	for(int x=0;x<n;x++){
		dp[x]=ans;
		ss.insert(arr[x].second);
		set<int>::iterator it=ss.find(arr[x].second),it2=it;
		if(it==ss.begin())s=-1;
		else{
			it2--;
			s=*it2;
		}
		it2=it;
		it2++;
		if(it2==ss.end())e=n;
		else{
			it2=it;
			it2++;
			e=*it2;
		}
		l=(e-s-1);
		ans-=(l*(l-1))/2 + l;
		l=arr[x].second-s-1;
		ans+=(l*(l-1))/2 + l;
		l=e-arr[x].second-1;
		ans+=(l*(l-1))/2 + l;
		//cout<<arr[x].first<<'\t'<<arr[x].second<<'\t'<<dp[x]<<'\t'<<s<<'\t'<<e<<'\n';
	}
	dp[n]=ans;//should be 0 already...
	//cout<<dp[n]<<'\n';
	for(int x=0;x<q;x++){
		a=get()
		//binary search the answer in dp array
		lo=0;hi=n;
		while(lo<hi){
			mid=(lo+hi)/2;//rounds down, impt since arr[n] doesn't exist
			if(arr[mid].first>a)lo=mid+1;
			else hi=mid;
		}
		cout<<dp[lo]<<'\n';
	}
	return 0;
}
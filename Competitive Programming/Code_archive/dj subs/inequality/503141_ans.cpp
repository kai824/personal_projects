// ans.cpp 10 Mar 19, 15:32:41 100 0.03 Judging completed in 3.298s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#pragma O3
typedef long long ll;

struct node{
	node(int ss,int ee){
	}
	ll ft[10005];
	ll ls(ll x){
    	return(x & (-x));
    }
    ll queryy(ll p){//sum of first p elements
    	ll sum=0;
    	for(;p;p-=ls(p))sum+=ft[p];
    	return sum;
    }
    void updatee(ll p,ll v){
    	for(;p<=10003;p+=ls(p)){
    		ft[p]+=v;//n is the number of elements
    	}
    }
	void update(ll p,ll new_val,ll s,ll e){
	    updatee(p,new_val);
	}
	
	ll query(ll a,ll b,ll s,ll e){
	    return queryy(b)-queryy(a-1);
	}
} *st1,*st2,*st3,*st4;
/*
1: count no. of stuff
2: sum no. xi yi
3: sum xi
4: sum yi

iterator: value of yi
*/
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,ans=0ll,xx,yy;
	cin>>n;
	pair<ll,ll> arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x].first>>arr[x].second;
	}
	sort(arr,arr+n);
	st1=new node(1,10000);
	st2=new node(1,10000);
	st3=new node(1,10000);
	st4=new node(1,10000);

	for(int x=0;x<n;x++){
		xx=arr[x].first;yy=arr[x].second;
		//positive part...
		ans+=xx * yy * st1->query(1,yy-1,1,10000);//xy
		ans+=st2->query(1,yy-1,1,10000);//xi yi
		ans-=yy*st3->query(1,yy-1,1,10000);//x xi
		ans-=xx*st4->query(1,yy-1,1,10000);//y yi
		//negative part...
		ans-=xx * yy * st1->query(yy+1,10000,1,10000);//xy
		ans-=st2->query(yy+1,10000,1,10000);//xi yi
		ans+=yy*st3->query(yy+1,10000,1,10000);//y xi
		ans+=xx*st4->query(yy+1,10000,1,10000);//x yi
		st1->update(yy,1,1,10000);
		st2->update(yy,xx*yy,1,10000);
		st3->update(yy,xx,1,10000);
		st4->update(yy,yy,1,10000);
	}
	cout<<ans;
	return 0;
}
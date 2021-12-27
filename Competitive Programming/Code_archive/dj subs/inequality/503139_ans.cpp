// ans.cpp 10 Mar 19, 15:19:15 100 0.17 Judging completed in 4.301s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define DEFAULT_VALUE 0ll
#define ONE 0ll

inline ll process(ll a,ll b){
    return a+b;
}

struct node{
	ll v;
	node *l=NULL,*r=NULL;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
	}
	
	void update(ll p,ll new_val,ll s,ll e){
	    if(p==s && p==e){
	        v+=new_val;
	        return;
	    }
	    if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node(s,(s+e)/2);
	        l->update(p,new_val,s,(s+e)/2);
	        if(r==NULL){
	            v=process(l->v,DEFAULT_VALUE);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }else{
	        //update the right...
	        if(r==NULL)r=new node(((s+e)/2) + 1,e);
	        r->update(p,new_val,((s+e)/2) + 1,e);
	        if(l==NULL){
	            v=process(DEFAULT_VALUE,r->v);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }
	}
	
	ll query(ll a,ll b,ll s,ll e){
	    if(a<=s&&e<=b)return v;
	    ll v_left,v_right;
	    if( ( (s+e)/2 )<a ){//left child not relevant
	        v_left=ONE;
	    }else{//left child relevant;
	        if(l==NULL)v_left=DEFAULT_VALUE;
	        else v_left=l->query(a,b,s,(s+e)/2);
	    }
	    if(b<=( (s+e)/2 ) ){//right child irrelvant
	        v_right=ONE;
	    }else{
	        if(r==NULL)v_right=DEFAULT_VALUE;
	        else v_right=r->query(a,b,((s+e)/2) + 1,e);
	    }
	    return process(v_left,v_right);
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
// ballgame.cpp 31 Jan 19, 19:56:04 66 1.43 Judging completed in 6.722s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#define DEFAULT_VALUE 0
#define ONE 0
typedef long long ll;
inline ll process(ll a,ll b){
    return ( (a+b)%1000000007);
}

struct node{
	ll v;
	node *l=NULL,*r=NULL;
	node(ll ss,ll ee){
		v=DEFAULT_VALUE;
	}
	
	void update(ll p,ll new_val,ll s,ll e){
	    if(p==s && p==e){
	        v=new_val;
	        v%=1000000007;
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
	    v%=1000000007;
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
} *root;

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return(a>b);
}

int ballgame(int n, int l, int d, int h[], int c[]) {
    pair<ll,ll> ppl[n];//height(to sort by), then coordinate
    long long ans=0,a;
    for(ll x=0;x<n;x++){
        ppl[x]=make_pair(h[x],c[x]);
    }
    sort(ppl,ppl+n,cmp);
    root=new node(0,1000000001);
    root->update(ppl[0].second,1,0,1000000001);
    for(ll x=1;x<n;x++){
        a=root->query(max(ppl[x].second-d,0LL),min(ppl[x].second+d,1000000001LL),0,1000000001);
        //so a will be no. of ways to reach student x
        root->update(ppl[x].second,a,0,1000000001);
        if(x==n-1){
            return ((int) (a%1000000007));
        }
    }
}
// ballgame.cpp 31 Jan 19, 20:36:24 0 1.25 Judging completed in 4.62s on AWS Oregon.
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
	
	void update(ll p,ll new_val,int s,int e){
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
	
	ll query(ll a,ll b,int s,int e){
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
    pair<int,int> ppl[n];//height(to sort by), then coordinate
    pair<int,pair<int,int> > lr[n];//middle, left, right
    //stores discretised, left, middle and right values
    pair<int,pair<int,char> > red[3*n];//for discretisation
    long long ans=0,a;
	int dis=0;
    for(ll x=0;x<n;x++){
        ppl[x]=make_pair(h[x],x);
        red[3*x].first=max(c[x]-d,0);
        red[3*x].second=make_pair(x,'0');
        red[3*x + 1].first=c[x];
        red[3*x + 1].second=make_pair(x,'1');
        red[3*x + 2].first=min(c[x]+d,1000000000);
        red[3*x + 2].second=make_pair(x,'2');
    }
    sort(red,red+3*n);
    for(int x=0;x<3*n;x++){
        if(x>0 && red[x].first!=red[x-1].first)dis++;
        if(red[x].second.second=='0') lr[red[x].second.first].second.first=dis;
        else if(red[x].second.second=='1') lr[red[x].second.first].first=dis;
        else if(red[x].second.second=='2') lr[red[x].second.first].second.second=dis;
    }
    sort(ppl,ppl+n,cmp);
    root=new node(0,dis);
    root->update(lr[ppl[0].second].first,1,0,dis);
    for(ll x=1;x<n;x++){
        a=root->query(max(lr[ppl[x].second].second.first,0),min(lr[ppl[x].second].second.second,dis),0,dis);
        //so a will be no. of ways to reach student x
        root->update(lr[ppl[x].second].first,a,0,dis);
        if(x==n-1){
            return ((int) (a%1000000007));
        }
    }
}
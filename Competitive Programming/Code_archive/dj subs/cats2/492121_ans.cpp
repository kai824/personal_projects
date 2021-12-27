// ans.cpp 16 Feb 19, 14:10:37 100 0.9 Judging completed in 4.901s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEFAULT_VALUE LLONG_MAX
#define ONE LLONG_MAX

ll process(ll a,ll b){
    return(min(a,b));
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
} *root;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    ll c[n+1],p[n+1];
    for(int x=0;x<=n;x++){
        cin>>c[x]>>p[x];
    }
    root=new node(0,n);
    //use segtree store min no. of cats seen by node x
    root->update(0,c[0],0,n);
	//cout<<"\n\n";
    for(int x=1;x<=n;x++){
        if(p[x]==0)continue;
        root->update(x,root->query(max(0LL,x-p[x]),x-1,0,n)+c[x],0,n);
		//cout<<root->query(max(0LL,x-p[x]),x-1,0,n)<<' '<<x<<' '<<c[x]<<'\n';
    }
    cout<<root->query(n,n,0,n);
    return 0;
}
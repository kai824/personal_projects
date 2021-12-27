// ans.cpp 14 Nov 18, 13:27:04 30 0.53 Judging completed in 3.084s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEFAULT_VALUE 0LL
#define ONE 0LL

inline ll process(ll a,ll b){
    return(a+b);
}

struct node{
	ll v;
	node *l=NULL,*r=NULL;
	node(ll ss,ll ee){
		v=DEFAULT_VALUE;
	}
	
	void update(ll p,ll new_val,ll s,ll e){
	    if(p==s && p==e){
	        v+=new_val;//change here to = new_val to modify the addition to set value
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
	    int v_left,v_right;
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
ll nn,int_min=INT_MIN,int_max=INT_MAX;
void init(ll N) {
    nn=N;
    root=new node(LLONG_MIN,LLONG_MAX);
}

void update(ll P, ll V) {
	P+=200000LL*int_max;
    root->update(P,V,LLONG_MIN,LLONG_MAX);
}

ll query(ll a, ll b){
	a+=200000LL*int_max;
	b+=200000LL*int_max;
    return root->query(a,b,LLONG_MIN,LLONG_MAX);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,k,a,ans=0;
    cin>>n>>k;
	init(n);
    ll ps[n+1];
    ps[0]=0;
    for(int x=1;x<=n;x++){
        cin>>a;
        ps[x]=ps[x-1]+a;
		//cout<<ps[x]<<' ';
    }//cout<<'\n';
	update(0,1LL);
    for(int x=1;x<=n;x++){        
		//cout<<"luol\n";
		ans+=query(LLONG_MIN,ps[x]-k);
		update(ps[x],1LL);
		//cout<<ans<<' ';
    }
    cout<<ans;
    return 0;
}
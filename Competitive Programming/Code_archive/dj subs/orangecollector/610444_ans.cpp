// ans.cpp 19 Nov 19, 07:59:29 100 0.99 Judging completed in 5.248s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define DEFAULT_VALUE 0
#define ONE 0

inline ll process(ll a,ll b){
    return(max(a,b));
}

struct node{
	ll v;
	node *l=NULL,*r=NULL;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
	}
	
	void update(int p,ll new_val,int s,int e){
	    if(p==s && p==e){
	        v=max(v,new_val);
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
	
	ll query(int a,int b,int s,int e){
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
} *root,*st[20];


int a[100005],c[100005],l[100005],r[100005];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int x=0;x<20;x++){st[x]=new node(0,1e5);}
    int n;
    long long ans=0,cur;
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>a[x]>>c[x]>>l[x]>>r[x];
    }
    for(int x=1;x<=n;x++){
        cur=0;
        for(int i=0;i<20;i++){
            if((c[x]&(1<<i))==0)continue;
            cur=max(cur,st[i]->query(l[x],r[x],0,1e5));
        }
        //cout<<cur<<'\n';
        cur+=a[x];
        ans=max(ans,cur);
        for(int i=0;i<20;i++){
            if(( c[x]&(1<<i) )==0)continue;
            st[i]->update(c[x],cur,0,1e5);
        }
    }
    cout<<ans;
    return 0;
}
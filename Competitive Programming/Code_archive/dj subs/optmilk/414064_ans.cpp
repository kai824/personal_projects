// ans.cpp 14 Nov 18, 23:24:41 0 0.03 Judging completed in 3.773s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

struct range{
    int nn=0,ny=0,yn=0,yy=0;
} DEFAULT_VALUE,ONE,tmp;

inline range process(range a,range b){
    range ans;
    ans.nn=max(a.ny+b.nn,a.nn+b.yn);
    ans.ny=max(a.nn+b.yy,a.ny+b.ny);
    ans.yn=max(a.yy+b.nn,a.yn+b.yn);
    ans.yy=max(a.yn+b.yy,a.yy+b.ny);
    return ans;
}

inline range single(int a){
    range ans;
    ans.nn=0;
    ans.yy=a;
    ans.ny=0;
    ans.yn=0;
    return ans;
}

struct node{
	range v;
	node *l=NULL,*r=NULL;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
	}
	
	void update(int p,int new_val,int s,int e){
	    if(p==s && p==e){
	        v=single(new_val);
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
	
	range query(int a,int b,int s,int e){
	    if(a<=s&&e<=b)return v;
	    range v_left,v_right;
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
int nn;
void init(int N) {
    nn=N;
    root=new node(0,nn-1);
}

void update(int P, int V) {
    root->update(P,V,0,nn-1);
}

range query(int a, int b){
    return root->query(a,b,0,nn-1);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,d,a,b,ans=0;
    cin>>n>>d;
    init(n);
    for(int x=0;x<n;x++){
        cin>>a;
        update(x,a);
    }
    for(int x=0;x<d;x++){
        cin>>a>>b;
		a--;//change 1-indexed to 0-indexed
        update(a,b);
        tmp=query(0,n-1);
        ans+=max(max(tmp.ny,tmp.yn),max(tmp.yy,tmp.nn));
    }
    cout<<ans<<'\n';
    return 0;
}
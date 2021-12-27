// ans.cpp 14 Nov 18, 11:40:02 100 1.78 Judging completed in 7.473s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#pragma O3
#define DEFAULT_VALUE 2e9
#define ONE 2e9

int process(int a,int b){
    return(min(a,b));
}

struct node{
	int v;
	node *l=NULL,*r=NULL;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
	}
	
	void update(int p,int new_val,int s,int e){
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
	
	int query(int a,int b,int s,int e){
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
int nn;
void init(int N) {
    nn=N;
    root=new node(0,N-1);
}

void update(int P, int V) {
    root->update(P,V,0,nn-1);
}

int query(int a, int b){
    return root->query(a,b,0,nn-1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,c,ans;
    cin>>n>>m;
    int d[n];
    init(1000000005);
    for(int x=0;x<n;x++){
        cin>>d[x];
        update(d[x],x);
    }
    for(int x=0;x<m;x++){
        cin>>a;
        if(a==0){
            cin>>b>>c;
			ans=query(b,c);
			if(ans==2e9)cout<<"-1\n";
            else cout<<query(b,c)<<'\n';
        }else{
            cin>>b>>c;
            update(d[b],c);
            update(d[c],b);
            swap(d[b],d[c]);
        }
    }
    return 0;
}
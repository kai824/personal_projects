// ans.cpp 28 Jan 18, 21:37:48 100 0.62 Judging completed in 5.196s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#define DEFAULT_VALUE 200004
#define ONE 200004
int arr[200005];
int process(int a,int b){
    if(a>b)swap(a,b);
    if(arr[a]>=arr[b]){
        return a;
    }else{
        return b;
    }
}

struct node{
	int v=DEFAULT_VALUE;
	node *l=NULL,*r=NULL;
	node(){}
	
	void update(int p,int new_val,int s,int e){
	    if(p==s && p==e){
	        v=new_val;
	        return;
	    }
	    if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node();
	        l->update(p,new_val,s,(s+e)/2);
	        if(r==NULL){
	            v=process(l->v,DEFAULT_VALUE);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }else{
	        //update the right...
	        if(r==NULL)r=new node();
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
int main() {
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    arr[200004]=INT_MIN;
    int n,m,a,b,c;
    root=new node();
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>arr[x];
        root->update(x,x,0,n-1);
    }
    for(int x=0;x<m;x++){
        cin>>a>>b;
        c=root->query(a,b,0,n-1);
        cout<<arr[c]<<'\n';
        arr[c]=-1;
        //cout<<'k';
        root->update(c,c,0,n-1);
    }
    return 0;
}
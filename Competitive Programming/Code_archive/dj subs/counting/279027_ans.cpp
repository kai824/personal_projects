// ans.cpp 5 Dec 17, 12:59:10 100 1.84 Judging completed in 5.414s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct node{
	map<int,int>v;//number, count
	node *l=NULL,*r=NULL;
	node(int ss,int ee){}
	
	void construct_update(int p,int new_val,int s,int e){
		if(p==s && p==e){
			if(v[new_val]==0){
	        	v[new_val]=1;
	        }else{
	        	v[new_val]++;
	        }
	        return;
		}
		if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node(s,(s+e)/2);
	        l->construct_update(p,new_val,s,(s+e)/2);
	    }else{
	        //update the right...
	        if(r==NULL)r=new node(((s+e)/2) + 1,e);
	        r->construct_update(p,new_val,((s+e)/2) + 1,e);
	    }
	    if(v[new_val]==0){
	    	v[new_val]=1;
	    }else{
	    	v[new_val]++;
	    }
	}
	
	void update(int p,int old_val,int new_val,int s,int e){
	    if(p==s && p==e){
	        v[old_val]--;
	        if(v[new_val]==0){
	        	v[new_val]=1;
	        }else{
	        	v[new_val]++;
	        }
	        return;
	    }
	    if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node(s,(s+e)/2);
	        l->update(p,old_val,new_val,s,(s+e)/2);
	    }else{
	        //update the right...
	        if(r==NULL)r=new node(((s+e)/2) + 1,e);
	        r->update(p,old_val,new_val,((s+e)/2) + 1,e);
	    }
	    
	    v[old_val]--;
	    if(v[new_val]==0){
	    	v[new_val]=1;
	    }else{
	    	v[new_val]++;
	    }
	}
	
	int query(int a,int b,int c,int s,int e){
	    if(a<=s&&e<=b){
	    	if(v[c]==0)return 0;
	    	return v[c];
	    }
	    int v_left,v_right;
	    if( ( (s+e)/2 )<a ){//left child not relevant
	        v_left=0;
	    }else{//left child relevant;
	        if(l==NULL)v_left=0;
	        else v_left=l->query(a,b,c,s,(s+e)/2);
	    }
	    if(b<=( (s+e)/2 ) ){//right child irrelvant
	        v_right=0;
	    }else{
	        if(r==NULL)v_right=0;
	        else v_right=r->query(a,b,c,((s+e)/2) + 1,e);
	    }
	    return v_left+v_right;
	}
} *root;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,a,b,c,d;
    cin>>n>>q;
    int arr[n+5];//1-indexed, like the input...
    root=new node(1,n);
    for(int x=1;x<=n;x++){
    	cin>>arr[x];
    	root->construct_update(x,arr[x],1,n);
    }
    for(int x=0;x<q;x++){
    	cin>>a;
    	if(a==1){
    		//query...
    		cin>>b>>c>>d;
    		cout<<root->query(b,c,d,1,n)<<'\n';
    	}else{
    		//update...
    		cin>>b>>c;//point, new value...
    		root->update(b,arr[b],c,1,n);
    		arr[b]=c;
    	}
    }
    return 0;
}
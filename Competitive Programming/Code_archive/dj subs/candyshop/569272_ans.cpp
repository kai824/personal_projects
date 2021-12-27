// ans.cpp 27 Oct 19, 15:58:03 100 0.63 Judging completed in 5.116s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,preorder[200005],a,b,nex=0;
bool visited[200005];

vector<int> adjlis[200005];
int subtree[200005],depth[200005],cc[200005],cc2[200005];

void build(int x,int dist){//visits parents before children...
    visited[x]=true;
    depth[x]=dist;
    preorder[x]=nex;nex++;
    for(int i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            //parents[adjlis[x][i] ]=x;
            build(adjlis[x][i],dist+1);
        }
    }
    subtree[x]=nex-1;
}

typedef long long ll;

#define DEFAULT_VALUE 0
#define ONE -1

inline int process(int a,int b){
	if(a==-1)return b;
	if(b==-1)return a;
    if(cc[a]>cc[b])return a;
    else return b;
}

struct node{
	int v;
	node *l=NULL,*r=NULL;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
	}
	
	void reset(){
	    v=DEFAULT_VALUE;
	    if(l!=NULL)l->reset();
	    if(r!=NULL)r->reset();
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

bool cmp(int a,int b){
    return(depth[a]>depth[b]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc,m,a,b,parent,ans,it;
    root=new node(1,200005);
    int arr[1000005];
    cin>>tc;
    for(int i=1;i<=tc;i++){
        root->reset();
		nex=0;
        cin>>n>>m>>a>>b;
		for(int x=0;x<n;x++){
            adjlis[x].clear();
			visited[x]=false;
        }
        for(int x=1;x<n;x++){
            cin>>parent;
            adjlis[parent].push_back(x);
        }
        build(0,0);
		for(ll x=0;x<m;x++){
			arr[x]=((a*x)+b)%n;
		}
		/*for(ll x=0;x<n;x++){
            cc[x]=0;
        }*/
        for(ll x=0;x<n;x++){
			cc[preorder[x]]=x;
			
        }
		for(ll x=0;x<n;x++){root->update(x,x,0,200005);}
        ans=0;
        sort(arr,arr+m,cmp);
        for(int x=0;x<m;x++){
			it=root->query(preorder[arr[x]],subtree[arr[x]],0,200005);
            if(cc[it]==0)continue;
            if(it==-1)continue;
            ans+=cc[it];
            cc[it]=0;
            root->update(it,it,0,200005);
        }
        cout<<"Case #"<<i<<": "<<ans<<'\n';
    }
    return 0;
}
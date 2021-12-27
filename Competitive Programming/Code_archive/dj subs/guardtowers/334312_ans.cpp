// ans.cpp 8 Mar 18, 09:35:06 0 0.95 Judging completed in 6.71s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag=0;
set<ll>ss;
set<ll>::iterator upper;
inline char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline int get()
{
    int ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}
ll n=get(),ans=-2*n;
pair<ll,ll> arr[2000000];

#define DEFAULT_VALUE 0
#define ONE 2e9

int process(int a,int b){
    return(min(a,b));
}

struct node{
	int v;
	node *l=NULL,*r=NULL;
	node(int x,int y){
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    root=new node(0,0);
    for(ll x=0;x<n;x++){
        arr[x].first=get();
        arr[x].second=x;
        if(flag)break;
    }
    sort(arr,arr+n,greater<pair<ll,ll> >());
    /*ss.insert(n);ss.insert(-1);
    for(ll x=0;x<n;x++){
        upper=ss.lower_bound(arr[x].second);
        ans+=*upper;
        upper--;
        ans-=*upper;
        //cout<<*ss.lower_bound(arr[x].second)<<'\n';
        ss.insert(arr[x].second);
    }*/
    for(ll x=0;x<n;x++){
    root->update(x,1,0,(1<<30));
    root->query(0,(1<<30),0,(1<<30));
    }
    cout<<ans;
}
//4 1 3 2 0
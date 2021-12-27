#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair

int last[500005],L[500005],R[500005];
int c[500005];
vector<int> v[500005];
pii rng[500005];//range...

void aq(){//to be kept for later...
  int q,a,b;
  cin>>q;
  while(q--){
    cin>>a>>b;
    a--;b--;
    if(rng[a].f<=b && b<=rng[a].s){
      cout<<"YES\n";
    }else cout<<"NO\n";
  }
}

int n;
struct st{
  int s,e;
  int ll,rr;
  st *l,*r;
  st(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
      ll=L[s];
      rr=R[s];
    }else{
      l=new st(s,(s+e)/2);
      r=new st((s+e)/2+1,e);
      ll=min(l->ll,r->ll);
      rr=max(l->rr,r->rr);
    }
  }
  int lsearch(int start,int limit){
    if(start<s)return start;
    if(start<e){
      int ans=-1;
      if((s+e)/2<start){
        ans=r->lsearch(start,limit);
        if(ans==-1)return l->lsearch(start,limit);
        return ans;
      }
      return l->lsearch(start,limit);
    }
    //includes whole range:
    if(rr<=limit)return -1;
    if(s==e)return s;
    if(r->rr<=limit)return l->lsearch(start,limit);
    else return r->lsearch(start,limit);
  }
  int rsearch(int start,int limit){
    if(e<start)return start;
    if(s<start){
      int ans=n-1;
      if(start<=(s+e)/2){
        ans=l->rsearch(start,limit);
        if(ans==n-1)return r->rsearch(start,limit);
        return ans;
      }
      return r->rsearch(start,limit);
    }
    //includes whole range
    if(ll>=limit)return n-1;
    if(s==e)return s;
    if(l->ll>=limit)return r->rsearch(start,limit);
    else return l->rsearch(start,limit);
  }
} *nx;

struct node{
  int mn=1e9,mx=-1;
  int s,e;
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
    }else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
    }
  }
  void upd(int p){
    mn=min(mn,rng[p].f);
    mx=max(mx,rng[p].s);
    if(s==e){
      return;
    }
    if(p<=(s+e)/2)l->upd(p);
    else r->upd(p);
  }
  pii query(int a,int b){
    if(a<=s && e<=b)return mp(mn,mx);
    pii ans=mp(1e9,-1),tmp;
    if(a<=(s+e)/2){
      ans=l->query(a,b);
    }
    if((s+e)/2<b){
      tmp=r->query(a,b);
      ans.f=min(ans.f,tmp.f);
      ans.s=max(ans.s,tmp.s);
    }
    return ans;
  }
} *root;

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int a;
  cin>>n;
  for(int i=0;i+1<n;i++){
    cin>>c[i];
  }
  for(int i=0;i<n;i++){
    cin>>a;
    v[i].resize(a);
    for(int j=0;j<a;j++){
      cin>>v[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    last[i]=-1;
  }
  for(int i=0;i+1<n;i++){//L[node]: nearest left node of same key...
    for(int x:v[i]){
      last[x]=i;
    }
    L[i]=last[c[i]];
  }
  for(int i=1;i<=n;i++)last[i]=1e9;
  for(int i=n-2;i>=0;i--){
    for(int x:v[i+1]){
      last[x]=i+1;
    }
    R[i]=last[c[i]];
  }

  root=new node(0,n-1);nx=new st(0,n-2);

  for(int i=0;i<n;i++){
    rng[i].f=rng[i].s=i;
    while(true){
      pii tmp=rng[i];
      // while(rng[i].f>0 && R[rng[i].f-1]<=rng[i].s)rng[i].f--;
      rng[i].f=nx->lsearch(rng[i].f-1,rng[i].s)+1;//expand left: first index where R[i]>rng[i].s
      rng[i].s=nx->rsearch(rng[i].s,rng[i].f);//expand right: first index where L[i]<rng[i].f
      // while(rng[i].s+1<n && L[rng[i].s]>=rng[i].f)rng[i].s++;

      if(tmp==rng[i])break;

      //fast expansion for hopefully amortized O(n log n)?
      tmp=root->query(rng[i].f,i);
      rng[i].f=min(rng[i].f,tmp.f);
      rng[i].s=max(rng[i].s,tmp.s);
    }
    root->upd(i);
    // cout<<i<<' '<<rng[i].f<<' '<<rng[i].s<<'\t'<<L[i]<<' '<<R[i]<<'\n';
  }

  aq();
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define int long long

struct node{
  node *l,*r;
  int s,e,ad=0,rm=0,rmd=0;//rmd: removed...
  node(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
    }else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
    }
  }
  void prop(){
    if(l){
      l->update(s,e,rm);
      l->update(s,e,ad);
      l->rmd+=rmd;
    }
    if(r){
      r->update(s,e,rm);
      r->update(s,e,ad);
      r->rmd+=rmd;
    }
    rm=ad=rmd=0;
  }
  void update(int a,int b,int c){
    if(a<=s && e<=b){
      if(c<0)rmd+=min(ad,-c);
      ad+=c;
      if(ad<0){
        rm+=ad;ad=0;
      }
      return;
    }
    prop();
    if(a<=(s+e)/2)l->update(a,b,c);
    if((s+e)/2<b)r->update(a,b,c);
  }
  int query(int p,int mn){//query for rmd...
    if(s==e){
      if(ad<mn)return -1;
      return rmd;
    }
    prop();
    if(p<=(s+e)/2)return l->query(p,mn);
    else return r->query(p,mn);
  }
} *root;

const int inf=LLONG_MAX;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>

int ans[250005],nex=0;
vector<pii> vv[250005];
struct node2{
  node2 *l,*r;
  int s,e,m,mm=inf;//mm stores which query is the nearest to being answered...
  int val=0;//similar to previous segtree
  node2(int ss,int ee){
    s=ss;e=ee;m=(s+e)/2;
    if(s==e){
      l=r=NULL;
    }else{
      l=new node2(s,m);
      r=new node2(m+1,e);
    }
  }
  void rev(){
    if(s==e){
      if(vv[s].size()==0)return;
      sort(vv[s].begin(),vv[s].end(),greater<pii>() );//smallest crossover value at back
      mm=vv[s].back().f;
    }else{
      l->rev();r->rev();
      mm=min(l->mm,r->mm);
    }
  }
  void join(int a,int b,int cnt,int typ){
    if(mm==inf)return;
    if(a<=s && e<=b && cnt<mm){
      val+=cnt;
      mm-=cnt;
      return;
    }else if(s==e){
      val+=cnt;
      while(vv[s].size()>0 && val>=vv[s].back().f){
        ans[vv[s].back().s]=typ;
        vv[s].pop_back();
      }
      mm=inf;
      if(vv[s].size()>0)mm=vv[s].back().f-val;
      return;
    }
    //prop: since it was left to lazy, nothing should happen...
    l->join(s,e,val,-1);
    r->join(s,e,val,-1);
    val=0;

    if(a<=m)l->join(a,b,cnt,typ);
    if(m<b)r->join(a,b,cnt,typ);

    mm=min(l->mm,r->mm);
  }
} *r2;

vector<pair<pii,pii> > mm;
int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,q;
  cin>>n>>m>>q;
  root=new node(1,n);
  r2=new node2(1,n);

  int a,b,c,d,e;
  while(q--){
    cin>>a;
    if(a==1){//people join the queue...
      cin>>b>>c>>d>>e;
      mm.eb(mp(b,c),mp(e,d));//range b to c, e customers, type d

      root->update(b,c,e);
    }else if(a==2){//people leave the queue...
      cin>>b>>c>>d;
      root->update(b,c,-d);
    }else{
      cin>>b>>c;//query shop b, cth customer...
      e=root->query(b,c);
      //cout<<"DEBUG"<<e<<'\n';
      if(e==-1)nex++;
      else{
        c+=e;
        vv[b].eb(c,nex++);
      }
    }
  }
  r2->rev();
  for(auto x:mm){
    r2->join(x.f.f,x.f.s,x.s.f,x.s.s);
  }

  for(int i=0;i<nex;i++){
    cout<<ans[i]<<'\n';
  }
  return 0;
}
/*
3 5 7
1 2 3 5 2
1 1 2 2 4
3 2 3
2 1 3 3
3 1 2
1 2 3 4 2
3 3 2
*/

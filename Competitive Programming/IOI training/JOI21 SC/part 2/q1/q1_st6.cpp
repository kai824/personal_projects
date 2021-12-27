#include<bits/stdc++.h>
using namespace std;

#define int long long

struct node{
  node *l,*r;
  int s,e,v=0;
  node(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
    }else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
    }
  }
  void update(int a,int b,int c){
    if(a<=s && e<=b){
      v+=c;
      return;
    }
    if(a<=(s+e)/2)l->update(a,b,c);
    if((s+e)/2<b)r->update(a,b,c);
  }
  int query(int p){
    if(s==e){
      return v;
    }
    l->v+=v;r->v+=v;v=0;
    if(p<=(s+e)/2)return l->query(p);
    else return r->query(p);
  }
} *root;

const int inf=LLONG_MAX;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>

int ans[250005],nex=0;
struct node2{
  node2 *l,*r;
  int s,e,mm=inf;//mm stores which query is the nearest to being answered...
  int val=0;//similar to previous segtree
  vector<pii> vv;//value, answer it
  node2(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
    }else{
      l=new node2(s,(s+e)/2);
      r=new node2((s+e)/2+1,e);
    }
  }
  void rev(){
    if(l)l->rev();if(r)r->rev();
    if(vv.size()>0)sort(vv.begin(),vv.end(),greater<pii>() );//smallest cross value behind...
  }
  void add(int p,int v,int it){//shop p, cross value v, update answer it...
    if(s==e){
      vv.eb(v,it);
      mm=min(mm,v-val);
      return;
    }
    if(p<=(s+e)/2)l->add(p,v,it);
    else r->add(p,v,it);

    mm=min(l->mm,r->mm);
  }
  void join(int a,int b,int cnt,int typ){
    if(a<=s && e<=b && cnt<mm){
      val+=cnt;
      mm-=cnt;
      return;
    }else if(s==e){
      val+=cnt;
      while(vv.size()>0 && val>=vv.back().f){
        ans[vv.back().s]=typ;
        vv.pop_back();
      }
      mm=inf;
      if(vv.size()>0)mm=vv.back().f-val;
      return;
    }
    //prop: since it was left to lazy, nothing should happen...
    l->join(s,e,val,-1);
    r->join(s,e,val,-1);
    val=0;

    if(a<=(s+e)/2)l->join(a,b,cnt,typ);
    if((s+e)/2<b)r->join(a,b,cnt,typ);

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
      //root->update(b,c,d);//just increment...
    }else{
      cin>>b>>c;//query shop b, cth customer...
      if(root->query(b)<c)nex++;//too few customers...
      //cout<<"Processed query: "<<b<<' '<<c<<'\n';
      else r2->add(b,c,nex++);
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

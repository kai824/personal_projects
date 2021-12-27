// ans.cpp 22 Feb 20, 13:27:51 74 1.33 Judging completed in 5.447s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
ll g;//location of central thingy...

struct node{
  ll s,e;
  ll lv,rv;//type of the leftmost and rightmost...
  ll cost,cnt,walk_time;//count of going back to central station in the middle
  //cost excludes walking time...
  bool lazy=false;
  node *l,*r;
  node(ll ss,ll ee){
    s=ss;e=ee;
    if(s==e){
      lv=rv=1;
      cost=cnt=walk_time=0;
      l=r=NULL;
    }else{
      //l=new node(s,(s+e)/2);
      //r=new node((s+e)/2+1,e);
      l=r=NULL;
      lv=rv=1;
      cost=0;cnt=0;
      walk_time=e-s;
    }
  }
  void rebuild(){
      if(s==e){
          l=r=NULL;
          cost=cnt=walk_time=0;
          return;
      }
    if(l==NULL)l=new node(s,(s+e)/2);
    if(r==NULL)r=new node((s+e)/2+1,e);
    if(lazy && s<e){
      lazy=false;
      l->lazy=r->lazy=true;
      l->lv=l->rv=r->lv=r->rv=lv;
      l->cost=l->cnt=r->cost=r->cnt=0;
      l->walk_time=l->e-l->s;
      r->walk_time=r->e-r->s;
    }
    if(l->cnt>0){
        l->rebuild();
    }
    if(r->cnt>0){
        r->rebuild();
    }
    lv=l->lv;rv=r->rv;
    cnt=l->cnt+r->cnt;
    cost=l->cost+r->cost;
    walk_time=l->walk_time+r->walk_time+1;
    if(l->rv!=r->lv){
      cnt++;
      if(g<=(s+e)/2)cost+=2*abs(g- l->e);
      else{
        cost+=2*abs(g - l->e) -1;
        walk_time--;
      }
    }
  }
  ll query(ll a,ll b){//left and right bounds...
    //includes walking time...
    if(lazy)return min(b,e)-max(a,s);//the whole range will be the same...
    if(a<=s && e<=b){
      return cost+walk_time;
    }
    if(b<=(s+e)/2){
      if(l==NULL)return min(b,e)-max(a,s);//only have walk time
      return l->query(a,b);
    }
    if((s+e)/2<a){
      if(r==NULL)return min(b,e)-max(a,s);
      return r->query(a,b);
    }
    if(l==NULL)l=new node(s,(s+e)/2);
    if(r==NULL)r=new node((s+e)/2+1,e);
    ll ans=l->query(a,b)+r->query(a,b)+1;
    if(l->rv!=r->lv){
      if(g<=(s+e)/2)ans+=2*abs(g- l->e);//go to back and forth...
      else ans+=2*abs(g- l->e)-2;//'cause -2 on walking...
    }
    return ans;
  }
  void update(ll a,ll b,ll t){//make the whole range the same...
    if(a<=s && e<=b){
      lazy=true;
      lv=rv=t;
      cost=cnt=0;
      walk_time=(e-s);
      //cout<<"lazy"<<s<<' '<<e<<' '<<lv<<' '<<rv<<'\n';
      return;
    }
    if(l==NULL)l=new node(s,(s+e)/2);
    if(r==NULL)r=new node((s+e)/2+1,e);
    if(lazy && s<e){
      lazy=false;
      l->lazy=r->lazy=true;
      l->lv=l->rv=r->lv=r->rv=lv;
      l->cost=l->cnt=r->cost=r->cnt=0;
      l->walk_time=l->e-l->s;
      r->walk_time=r->e-r->s;
    }
    if(a<=(s+e)/2){
      l->update(a,b,t);
    }
    if((s+e)/2<b){
      r->update(a,b,t);
    }
    lv=l->lv;rv=r->rv;
    cnt=l->cnt+r->cnt;
    cost=l->cost+r->cost;
    walk_time=l->walk_time+r->walk_time+1;
    if(l->rv!=r->lv){
      cnt++;
      if(g<=(s+e)/2)cost+=2*abs(g- l->e);
      else{
        cost+=2*abs(g - l->e) -1;
        walk_time--;
      }
    }
    //cout<<"normal"<<s<<' '<<e<<' '<<cost<<' '<<lv<<' '<<rv<<'\n';
  }
} *root;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  ll s,d;
  cin>>s>>g>>d;//no. of shelves, location of central place, no. of duties...

  root=new node(1,s);

  ll t,l,r;
  while(d--){
    cin>>t;
    if(t==1){
      cin>>l>>r;//take stuff from shelve l to r...
      cout<<root->query(l,r)+(r-l+1ll)+abs(g-l)+abs(g-r)<<'\n';
    }else if(t==2){
      cin>>l>>r>>t;
      root->update(l,r,t);
    }else{
      cin>>g;//the new g...
      root->rebuild();
    }
  }
  return 0;
}
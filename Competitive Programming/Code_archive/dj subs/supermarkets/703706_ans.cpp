// ans.cpp 22 Feb 20, 12:37:00 36 0.97 Judging completed in 5.168s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
ll g;//location of central thingy...

struct node{
  ll s,e,ref;//reference point for central thing
  ll lv,rv;//type of the leftmost and rightmost...
  ll cost,cnt,walk_time;//count of going back to central station in the middle
  //cost excludes walking time...
  bool lazy=false,lazy2=false;//lazy2 is for type 3 queries...
  node *l,*r;
  node(ll ss,ll ee){
    ref=g;
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
  ll query(ll a,ll b){//left and right bounds...
    //includes walking time...
    if(lazy)return min(b,e)-max(a,s);//the whole range will be the same...
    if(a<=s && e<=b){
      return cost+walk_time;
    }
    if(lazy2){
      l->update2(1,s);
      r->update2(1,s);
      lazy2=false;
    }
    if(b<=(s+e)/2){
      if(l==NULL)return min(b,e)-max(a,s);//only have walk time
      return l->query(a,b);
    }
    if((s+e)/2<a){
      if(r==NULL)return min(b,e)-max(a,s);
      return r->query(a,b);
    }
    ll ans=1,f1,f2;
    if(l==NULL){
      f1=1;
      ans+=min(b,(s+e)/2)-max(a,s);
    }else{
      f1=l->rv;
      ans+=l->query(a,b);
    }
    if(l==NULL){
      f2=1;
      ans+=min(b,e)-max(a,(s+e)/2+1);
    }else{
      f2=r->lv;
      ans+=r->query(a,b);
    }
    if(f1!=f2){
      if(g<=(s+e)/2)ans+=2*abs(g- l->e);//go to back and forth...
      else ans+=2*abs(g- l->e)-2;//'cause -2 on walking...
    }
    return ans;
  }
  void self_check(){
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
  void update(ll a,ll b,ll t){//make the whole range the same...
    if(a<=s && e<=b){
      lazy=true;
      lv=rv=t;
      cost=cnt=0;
      walk_time=(e-s);
      lazy2=false;//if cnt is now 0, it has no use...
      //cout<<"lazy"<<s<<' '<<e<<' '<<lv<<' '<<rv<<'\n';
      return;
    }
    if(l==NULL)l=new node(s,(s+e)/2);
    if(r==NULL)r=new node((s+e)/2+1,e);
    if(lazy2 && s<e){
      l->update2(1,s);
      r->update2(1,s);
      lazy2=false;
    }
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
    self_check();
    //cout<<"normal"<<s<<' '<<e<<' '<<cost<<' '<<lv<<' '<<rv<<'\n';
  }
  void update2(ll a,ll b){
     assert(a<=b);
    if(a<=s && e<=b){
      lazy2=true;
      if(e<=min(g,ref)){//left side...
        cost+=cnt*(g-ref)*2;
      }else if(max(g,ref)<=s){//right side...
        cost-=cnt*(g-ref)*2;
      }else{
        if(ref<g){
          cost=cnt*(2*g-1)-(cost+ (cnt*2*ref) );
          walk_time-=cnt;
        }else{
          cost=-(2*g+1)*cnt  -cost + (cnt*2*ref);
          walk_time+=cnt;
        }
      }
      ref=g;
      return;
    }
    if(lazy)return;
    //if lazy, means everything below no need go back counter, so no point doing stuff
    if(a<=(s+e)/2){
      if(l!=NULL)l->update2(a,b);
    }
    if((s+e)/2<b){
      if(r!=NULL)r->update2(a,b);
    }
    /*if(l==NULL)l=new node(s,(s+e)/2);
    if(r==NULL)r=new node((s+e)/2+1,e);
    self_check();*/
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
      l=g;
      cin>>g;//the new g...
      if(g==l)continue;
      root->update2(1,min(g,l));
      if(abs(g-l)>=2)root->update2(min(g,l)+1,max(g,l)-1);
      root->update2(max(g,l),s);
    }
  }
  return 0;
}
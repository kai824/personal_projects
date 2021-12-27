#include "candies.h"
#include<bits/stdc++.h>
using namespace std;

#define lnt long long
const lnt inf=1e17;
typedef pair<lnt,lnt> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back

vector<pii> delt[200005];

pii ma,mi;//suffix min max...

struct node{
  int s,e;
  pii sma,smi;//min max... (with its index...)
  lnt lz=0;
  node *l,*r;
  node(int ss,int ee){
    sma=smi=mp(0,ss);
    s=ss;e=ee;
    if(s==e)l=r=NULL;
    else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
    }
  }
  void prop(){
    l->sma.f+=lz;
    l->smi.f+=lz;
    l->lz+=lz;
    r->sma.f+=lz;
    r->smi.f+=lz;
    r->lz+=lz;
    lz=0;
  }
  void update(int a,int b,lnt d){
    if(a<=s && e<=b){
      sma.f+=d;
      smi.f+=d;
      lz+=d;
      return;
    }
    prop();
    if(a<=(s+e)/2)l->update(a,b,d);
    if((s+e)/2<b)r->update(a,b,d);
    smi=min(l->smi,r->smi);
    sma=max(l->sma,r->sma);
  }
  pair<pii,pii> bs(int x){//global ma and mi are on the right of current node...
    if(max(ma.f,sma.f)-min(mi.f,smi.f)<x || s==e)return mp(min(mi,smi),max(ma,sma));
    prop();
    if(max(ma.f,r->sma.f)-min(mi.f,r->smi.f)>=x)return r->bs(x);
    ma=max(ma,r->sma);
    mi=min(mi,r->smi);
    return l->bs(x);
  }

  void output(){
    cout<<"Range of "<<s<<" to "<<e<<" has "<<smi.f<<' '<<smi.s<<" and "<<sma.f<<' '<<sma.s<<'\n';
    if(l)l->output();
    if(r)r->output();
  }
}*root;

vector<int> distribute_candies(vector<int> c, vector<int> l,
                                    vector<int> r, vector<int> v) {
    int n = c.size(),q=l.size();
    for(int i=0;i<q;i++){
      r[i]++;
      delt[l[i]].eb(i+1,v[i]);
      if(r[i]<n)delt[r[i]].eb(i+1,-v[i]);//else don't bother since we won't need to un-update it...
    }
    root=new node(0,q);//0-value at 0...

    lnt end=0;

    vector<int> ans;
    for(int i=0;i<n;i++){
      for(pii x:delt[i]){
        //cerr<<"Update "<<x.f<<' '<<q<<'\t'<<x.s<<'\n';
        root->update(x.f,q,x.s);
        end+=x.s;
      }
      //answer query: first, we find the last big inc/dec (larger than c[i]...)
      ma=mp(-inf,-1);mi=mp(inf,-1);
      pair<pii,pii> p=(root->bs(c[i]));//pair of smi, sma...

      //root->output();
      //cerr<<"Answering query "<<i<<' '<<p.f.f<<' '<<p.f.s<<'\t'<<p.s.f<<' '<<p.s.s<<'\n';

      if(p.f.s<p.s.s){//max came later...
        ans.push_back(c[i]-(p.s.f-end));
      }else{
        ans.push_back(end-p.f.f);
      }
    }
    return ans;
}

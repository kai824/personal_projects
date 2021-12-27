#include "grass.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

/*struct node{
  int s,e,v,lz;
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    l=r=NULL;
    v=lz=0;
  }
} *root;*/
ll cur=0;
inline void add(ll a,ll b,ll c){
  cur+=((b-a+1)*c);
}

ll ad;
list<pair<pii,ll> > rngs;//ranges
list<pair<pii,ll> >::iterator it,it2;
void cap(ll lim){
  if(it->s+ad>lim){
    add(it->f.f,it->f.s,(lim-ad)-it->s);
    it->s=(lim-ad);
    it2=it;it2++;
    while(it2!=rngs.end()){
      if(it2->s+ad>lim){
        add(it2->f.f,it2->f.s,(lim-ad)-it2->s);
        it2->s=(lim-ad);
        it2++;
      }else break;
    }
    it2=it;
    while(it2!=rngs.begin()){it2--;
      if(it2->s+ad>lim){
        add(it2->f.f,it2->f.s,(lim-ad)-it2->s);
        it2->s=(lim-ad);
      }else break;
    }
  }
}

vector<ll> simulate(int n,int h,int m, vector<char> events, vector<int> x) {//m events
  cur=0;
  //root=new node(1,n);

  ad=0;
  rngs.clear();
  rngs.eb(mp(1,n),0);//it points to biggest range...
  it=rngs.begin();

  vector<ll> ans;
  for(int i=0;i<m;i++){
    if(events[i]=='N'){//grow...
      cap(h-x[i]);
      ad+=x[i];
      add(1,n,x[i]);
    }else if(events[i]=='L'){//trim stuff on the left...
      if(x[i]==n){//reset whole thing...
        rngs.clear();
        ad=cur=0;
        rngs.eb(mp(1,n),0);
        it=rngs.begin();
        continue;
      }
      while(rngs.front().f.s<=x[i]){
        if(rngs.begin()==it)it++;
        add(rngs.front().f.f,rngs.front().f.s,-(rngs.front().s+ad));
        rngs.pop_front();
      }
      if(rngs.front().s+ad==0){
        rngs.front().f.f=1;
        continue;
      }
      add(rngs.front().f.f,x[i],-(rngs.front().s+ad));
      rngs.front().f.f=x[i]+1;
      rngs.emplace_front(mp(1,x[i]),-ad);
    }else if(events[i]=='D'){//right...
      if(x[i]==n){//reset whole thing...
        rngs.clear();
        ad=cur=0;
        rngs.eb(mp(1,n),0);
        it=rngs.begin();
        continue;
      }
      while(rngs.back().f.s<=x[i]){
        if(--rngs.end()==it)it--;
        add(rngs.back().f.f,rngs.back().f.s,-(rngs.back().s+ad));
        rngs.pop_back();
      }
      if(rngs.back().s+ad==0){
        rngs.back().f.s=n;
        continue;
      }
      add(n-x[i]+1,rngs.back().f.s,-(rngs.back().s+ad));
      rngs.back().f.s=n-x[i];
      rngs.emplace_back(mp(n-x[i]+1,n),-ad);
    }else if(events[i]=='S'){//cap them at height S...
      cap(x[i]);
    }else{//query
      ans.push_back(cur);
    }
  }

  return ans;
}

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>

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
  int query(int p,bool clear=false){
    if(s==e){
      if(clear){
        int ans=v;
        v=0;
        return ans;
      }
      return v;
    }
    l->v+=v;r->v+=v;v=0;
    if(p<=(s+e)/2)return l->query(p,clear);
    else return r->query(p,clear);
  }
} *root;

deque<pair<int,pii> > dq[65005];//size, type, prefix sum...
int os[65005];//offset

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,q;
  cin>>n>>m>>q;
  root=new node(1,n);

  int a,b,c,d,e;
  while(q--){
    cin>>a;
    if(a==1){//people join the queue... small number...
      cin>>b>>c>>d>>e;
      for(int i=b;i<=c;i++){
        a=root->query(i,true);
        while(dq[i].size()>0 && a>0){
          if(dq[i][0].f<=a){
            os[i]+=dq[i][0].f;
            a-=dq[i][0].f;
            dq[i].pop_front();
          }else{
            dq[i][0].f-=a;
            os[i]+=a;
            a=0;
          }
        }
        if(dq[i].size()==0){
          os[i]=0;
          dq[i].eb(e,mp(d,e));
        }else{
          dq[i].eb(e,mp(d,e+dq[i].back().s.s));
        }
      }
    }else if(a==2){//people leave the queue...
      cin>>b>>c>>d;
      root->update(b,c,d);
    }else{
      cin>>b>>c;//query shop b, cth customer...
      int i=b;
      a=root->query(i,true);
      while(dq[i].size()>0 && a>0){
        if(dq[i][0].f<=a){
          os[i]+=dq[i][0].f;
          a-=dq[i][0].f;
          dq[i].pop_front();
        }else{
          dq[i][0].f-=a;
          os[i]+=a;
          a=0;
        }
      }
      if(dq[i].size()==0 || dq[i].back().s.s-os[i]<c){
        cout<<"0\n";
        continue;
      }
      int lo=0,hi=dq[i].size()-1,mid;
      while(lo<hi){
        mid=lo+((hi-lo)/2);
        if(dq[i][mid].s.s-os[i]<c)lo=mid+1;
        else hi=mid;
      }
      cout<<dq[i][lo].s.f<<'\n';
    }
  }
}

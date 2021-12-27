#include "jumps.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back

int lef[200005][19];
int par[200005][19],n;

int par2[200005][19];//towards the left...
int hh[200005];
//might AC...
struct node{//range max... can also sparse table but wtv
  int s,e,v;
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    v=0;
    if(s==e){
      l=r=NULL;
      v=hh[s];
    }
    else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
      v=max(l->v,r->v);
    }
  }
  int query(int a,int b){
    if(a<=s && e<=b)return v;
    int ans=-1;
    if(a<=(s+e)/2)ans=l->query(a,b);
    if((s+e)/2<b)ans=max(ans,r->query(a,b));
    return ans;
  }
} *root;

void init(int N, vector<int> h){
  n=N;
  vector<pii> v;
  v.eb(h.back(),h.size()-1);
  par[n-1][0]=-1;
  for(int i=h.size()-2;i>=0;i--){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()==0)par[i][0]=-1;
    else par[i][0]=v.back().s;
    v.eb(h[i],i);
  }
  for(int i=1;i<19;i++){//initialise the 2k decomp
    for(int j=0;j<n;j++){
      if(par[j][i-1]==-1)par[j][i]=-1;
      else par[j][i]=par[par[j][i-1]][i-1];
    }
  }
  v.clear();

  v.eb(h[0],0);
  par2[0][0]=-1;
  for(int i=1;i<n;i++){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()==0)par2[i][0]=-1;
    else par2[i][0]=v.back().s;
    v.eb(h[i],i);
  }
  for(int i=1;i<19;i++){//initialise the 2k decomp
    for(int j=0;j<n;j++){
      if(par2[j][i-1]==-1)par2[j][i]=-1;
      else par2[j][i]=par2[par2[j][i-1]][i-1];
    }
  }

  for(int i=0;i<n;i++)hh[i]=h[i];
  root=new node(0,n-1);

  int s;
  for(int i=0;i<n;i++){
    for(int j=0;j<19;j++){
      //compute lef[i][j]...
      if(par2[i][j]==-1){lef[i][j]=0;continue;}
      s=i;lef[i][j]=0;
      for(int k=18;k>=0;k--){
        if(par2[s][k]==-1 || hh[par2[s][k]]>hh[par[i][j]])continue;
        s=par2[s][k];
        lef[i][j]+=(1<<k);
      }
    }
  }
}

#ifdef local
bool debug=true;
#else
bool debug=false;
#endif

int minimum_jumps(int a, int b, int c, int d){//0-indexed
  int s=b,mm=root->query(c,d);
  if(hh[s]>mm){
    return -1;
  }
  for(int i=18;i>=0;i--){//max in range that is ok...
    if(par2[s][i]==-1)continue;
    if(hh[par2[s][i]]>mm)continue;
    if(par2[s][i]<a)continue;
    s=par2[s][i];
  }
  if(debug)cout<<"haha1 "<<s<<'\n';
  int ans=0,acc=0;
  for(int i=18;i>=0;i--){//just nice go before c...
    if(par[s][i]==-1)continue;
    if(par[s][i]>=c)continue;
    if(lef[s][i]!=0 && lef[s][i]+1-acc<(1<<i)){
      ans-=acc;
      ans+=lef[s][i]+1;
      acc=1;
    }else{
      ans+=(1<<i);
      acc+=(1<<i);
    }
    s=par[s][i];
  }
  if(debug)cout<<"haha2 "<<s<<' '<<acc<<' '<<ans<<' '<<lef[s][0]<<'\n';
  if(par[s][0]>d || par[s][0]==-1 || par[s][0]<c)return -1;
  if(lef[s][0]!=0 && lef[s][0]+1-acc<1){
    ans+=lef[s][0]+1-acc;
  }else{
    ans++;
  }
  //cout<<s<<"haha\n";
  return ans;
}

//for ST5...
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

bool s1;
int n,q,ans;
vector<int> adjl[120005];
vector<pair<int,pii> > qq[120005];//root node here...

int h1[120005],hh[120005],anss[120005];
int par[120005][19],rt[120005];//root of decomp (wtv u call it)
void dfs(int node,int prev=-1){//find height of max subtree...
  par[node][0]=prev;
  if(s1==false){
    for(int i=1;i<19;i++){
      if(par[node][i-1]==-1)par[node][i]=-1;
      else par[node][i]=par[par[node][i-1]][i-1];
    }
  }

  if(prev==-1)hh[node]=1;
  else hh[node]=hh[prev]+1;
  h1[node]=1;
  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs(x,node);
    h1[node]=max(h1[node],h1[x]+1);
  }
}
void dfs2(int node,int prev=-1){
  if(prev==-1 || h1[prev]>h1[node]+1)rt[node]=node;
  else rt[node]=rt[prev];
  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs2(x,node);
  }
}
int lca(int a,int b){
  if(hh[a]<hh[b])swap(a,b);
  for(int i=18;i>=0;i--){
    if(hh[a]-(1<<i)>=hh[b])a=par[a][i];
  }
  if(a==b)return a;
  for(int i=18;i>=0;i--){
    if(par[a][i]!=par[b][i]){
      a=par[a][i];b=par[b][i];
    }
  }
  return par[a][0];
}
void gather(int a,int c,vector<pii> &v){
  v.clear();
  while(true){
    if(a==c){
      v.eb(h1[c],h1[c]);
      break;
    }
    if(hh[rt[a]]>hh[c]){
      v.eb(h1[a],h1[rt[a]]);
      a=par[rt[a]][0];
    }else{
      v.eb(h1[a],h1[c]);
      break;
    }
  }
}
vector<int> v1,v2;
void solve1(){
  s1=true;
  int a,b,r;
  for(int i=1;i<=n;i++){
    adjl[i].clear();
    qq[i].clear();
  }
  for(int i=1;i<n;i++){
    cin>>a>>b;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }
  for(int i=0;i<q;i++){
    cin>>r>>a>>b;
    qq[r].eb(i,mp(a,b));
  }
  for(int i=1;i<=n;i++){
    if(qq[i].size()==0)continue;
    dfs(i);
    for(auto x:qq[i]){
      v1.clear();v2.clear();
      a=x.s.f;b=x.s.s;
      while(a!=b){
        if(hh[a]>=hh[b]){
          v1.push_back(h1[a]);
          a=par[a][0];
        }else{
          v2.push_back(h1[b]);
          b=par[b][0];
        }
      }
      v1.push_back(h1[a]);

      anss[x.f]=v2.size();
      anss[x.f]=(anss[x.f]*(anss[x.f]-1))/2;
      a=0;

      for(int j=0;j<v1.size();j++){
        while(a<v2.size() && v2[a]<v1[j])a++;
        anss[x.f]+=a;
      }
    }
  }

  for(int i=0;i<q;i++)cout<<anss[i]<<'\n';
}

vector<pii>vv1,vv2;
void solve2(){
  s1=false;
  int a,b,c,d,r,p2,ss;
  for(int i=1;i<=n;i++)adjl[i].clear();
  for(int i=1;i<n;i++){
    cin>>a>>b;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }
  dfs(1);dfs2(1);
  while(q--){
    cin>>r>>a>>b;

    c=lca(a,b);
    ans=hh[b]-hh[c];
    ans=(ans*(ans-1))/2;//inversions on the downslope part...

    gather(a,c,vv1);//should be done in ~400 operations

    gather(b,c,vv2);
    vv2.back().s--;
    if(vv2.back().f>vv2.back().s)vv2.pop_back();

    p2=ss=0;

    // for(pii x:v1)cout<<x.f<<' '<<x.s<<'\n';cout<<'\n';
    // for(pii x:v2)cout<<x.f<<' '<<x.s<<'\n';cout<<'\n';

    for(pii x:vv1){
      while(p2<vv2.size() && vv2[p2].s<x.f){//complete overtakes...
        ss+=vv2[p2].s-vv2[p2].f+1;
        p2++;
      }
      ans+=(x.s-x.f+1)*ss;
      // cerr<<ans<<' '<<p2<<'\n';
      while(p2<vv2.size() && vv2[p2].s<=x.s){
        ans+=(x.s-max(x.f,vv2[p2].f)+1)*(vv2[p2].s-vv2[p2].f+1);
        d=vv2[p2].s-max(x.f,vv2[p2].f)+1;
        ans-=(d*(d+1))/2;

        ss+=vv2[p2].s-vv2[p2].f+1;
        p2++;
      }
      // cerr<<ans<<' '<<p2<<'\n';
      if(p2<vv2.size() && vv2[p2].f<x.s){
        if(vv2[p2].f<x.f){
          d=x.s-x.f;
          ans+=(d*(d+1))/2;
          ans+=(x.s-x.f+1)*(x.f-vv2[p2].f);
          continue;
        }
        d=x.s-vv2[p2].f;
        ans+=(d*(d+1))/2;
      }
    }

    cout<<ans<<'\n';
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int tc;
  cin>>tc;
  while(tc--){
    cin>>n>>q;
    if(n<=2500)solve1();
    else solve2();
  }
  return 0;
}
/*
1
4 4
1 2
1 3
2 4
1 4 3
1 3 4
1 2 2
1 3 1
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#ifdef local
bool db=true;
#else
bool db=false;
#endif

vector<int> adjl[120005];
vector<pii> v1,v2,v3;//ranges of hr

int h1[120005],h2[120005],hu[120005];//deepest, second deepest, and from the parent...
int hh[120005];//depth
int par[120005][19],rt[120005],rt2[120005];//root of decomp (wtv u call it)
void dfs(int node,int prev=-1){//find height of max subtree...
  par[node][0]=prev;
  for(int i=1;i<19;i++){
    if(par[node][i-1]==-1)par[node][i]=-1;
    else par[node][i]=par[par[node][i-1]][i-1];
  }

  if(prev==-1)hh[node]=1;
  else hh[node]=hh[prev]+1;
  h1[node]=h2[node]=1;

  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs(x,node);
    if(h1[x]+1>=h1[node]){
      h2[node]=h1[node];
      h1[node]=h1[x]+1;
    }else if(h1[x]+1>h2[node]){
      h2[node]=h1[x]+1;
    }
  }
}
void dfs2(int node,int prev=-1){
  hu[node]=1;//furthest path if you go node->prev->... (and not go node)
  if(prev!=-1){
    if(h1[prev]==h1[node]+1){
      hu[node]=max(hu[node],h2[prev]+1);
    }else{
      hu[node]=max(hu[node],h1[prev]+1);
    }
    hu[node]=max(hu[node],hu[prev]+1);
  }

  if(prev==-1 || h1[prev]>h1[node]+1)rt[node]=node;
  else rt[node]=rt[prev];
  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs2(x,node);
  }
}
void dfs3(int node,int prev=-1){
  if(prev==-1 || hu[prev]+1<hu[node])rt2[node]=node;
  else rt2[node]=rt2[prev];
  for(int x:adjl[node]){
    if(x!=prev)dfs3(x,node);
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
void gather2(int aa,int cc,vector<pii> &v,int r){//on hu array, but should get the child node instead!
  v.clear();
  int a=aa,c=cc,h;
  if(r==aa){
    h=max(h1[r],hu[r]);
  }else if(aa==cc){//means that the root is as good as node 1...
    v.eb(h1[aa],h1[aa]);
    return;
  }else{//take any path, except the one going to r
    if(hu[a]>=h1[a])h=hu[a];//definitely safe
    else{
      if(h1[a]==h1[r]+(hh[r]-hh[a])){
        h=max(h2[a],hu[a]);
      }else h=h1[a];
    }
  }
  v.eb(h,h);
  if(aa==cc)return;
  /*if(r==aa){
    v.eb(max(h1[r],hu[r]),max(h1[r],hu[r]));
    if(aa==cc)return;
    //aa=par[aa][0];
  }else if(aa==cc){//means that the root is as good as node 1...
    v.eb(h1[aa],h1[aa]);
    return;
  }else{
    for(int x:adjl[aa]){
      if(x!=par[aa][0]){
        a=x;
        break;
      }
    }
    if(a==aa){
      v.eb(hu[a],hu[a]);
    }
  }*/

  while(true){
    if(par[a][0]==c){
      v.eb(hu[a]-1,hu[a]-1);
      break;
    }
    if(a==c)break;
    if(hh[rt2[a]]>hh[c]){
      v.eb(hu[rt2[a]]-1,hu[a]-1);
      a=par[rt2[a]][0];
    }else{
      v.eb(hu[c],hu[a]-1);
      break;
    }
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int tc,n,q,ans;
  cin>>tc;
  while(tc--){
    cin>>n>>q;
    int a,b,c,c2,d,r,p2,ss;
    for(int i=1;i<=n;i++)adjl[i].clear();
    for(int i=1;i<n;i++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    dfs(1);dfs2(1);dfs3(1);

    if(db)
    for(int i=1;i<=n;i++){
      cout<<i<<' '<<hu[i]<<' '<<rt2[i]<<'\n';
    }

    while(q--){
      cin>>r>>a>>b;

      c=lca(a,b);
      c2=lca(a,r);d=lca(b,r);
      if(c2==d){//as good as rooted at 1..,
        c2=c;
      }else{
        if(hh[c2]>hh[d]){
          d=c2;
          swap(c,c2);//a goes to c, b goes to c2...
        }else{
          c=d;
          swap(c,c2);
        }
      }
      if(db)cout<<a<<' '<<b<<' '<<c<<' '<<c2<<'\n';

      gather(a,c,v1);//should be done in ~400 operations
      v1.back().s--;
      if(v1.back().f>v1.back().s)v1.pop_back();

      gather(b,c2,v2);
      v2.back().s--;
      if(v2.back().f>v2.back().s)v2.pop_back();

      if(hh[c]>hh[c2]){
        gather2(c,c2,v3,r);//and push into v2...
        for(pii x:v3)v2.push_back(x);
      }else{
        gather2(c2,c,v3,r);//and push into v1...
        for(pii x:v3)v1.push_back(x);
      }
      sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
      if(db){
        for(pii x:v1)cout<<x.f<<' '<<x.s<<'\n';cout<<'\n';
        for(pii x:v2)cout<<x.f<<' '<<x.s<<'\n';cout<<'\n';
      }

      ans=0;
      for(pii x:v2){
        ans+=(x.s-x.f+1);
      }
      ans=(ans*(ans-1))/2;//inversions on the downslope part...

      p2=ss=0;

      for(pii x:v1){
        while(p2<v2.size() && v2[p2].s<x.f){//complete overtakes...
          ss+=v2[p2].s-v2[p2].f+1;
          p2++;
        }
        ans+=(x.s-x.f+1)*ss;
        // cerr<<ans<<' '<<p2<<'\n';
        while(p2<v2.size() && v2[p2].s<=x.s){
          ans+=(x.s-max(x.f,v2[p2].f)+1)*(v2[p2].s-v2[p2].f+1);
          d=v2[p2].s-max(x.f,v2[p2].f)+1;
          ans-=(d*(d+1))/2;

          ss+=v2[p2].s-v2[p2].f+1;
          p2++;
        }
        // cerr<<ans<<' '<<p2<<'\n';
        if(p2<v2.size() && v2[p2].f<x.s){
          if(v2[p2].f<x.f){
            d=x.s-x.f;
            ans+=(d*(d+1))/2;
            ans+=(x.s-x.f+1)*(x.f-v2[p2].f);
            continue;
          }
          d=x.s-v2[p2].f;
          ans+=(d*(d+1))/2;
        }
      }

      cout<<ans<<'\n';
    }
  }
  return 0;
}
/*
1
4 6
1 2
1 3
2 4
1 4 3
1 3 4
1 2 2
1 3 1
2 4 3
4 4 2


1
10 1

1 2
1 3
1 5
1 8
2 4
2 9
4 10
5 6
6 7
*/

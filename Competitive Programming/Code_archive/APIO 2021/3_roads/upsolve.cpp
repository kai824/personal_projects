//CMS closed, and no avenue for submitting for now, so submitting to: https://codeforces.com/contest/1119/problem/F
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define eb emplace_back
#define f first
#define s second
#define mp make_pair

#define debug(a) ; //cerr<<"YEET"<<a<<'\n';
#define debl(a,b) ; //cerr<<a<<" value "<<b<<'\n';

const int maxn=250005;
int n;
vector<pii> adjl[maxn];//node
vector<pair<pii,int> > adjlt[maxn];//node, weight, index of reverse edge

vector<int> toc;//to consider
bool vis[maxn],act[maxn];//activated nodes

struct node{
  int s,e,it;
  int cnt=0,sm=0;//count, sum...
  node *l,*r;
  //node(int ss,int ee,int ii){build(ss,ee,ii);}
  node(int ss,int ee,int ii){
    s=ss;e=ee;it=ii;
    l=r=NULL;
    if(s<e){
      l=new node(s,(s+e)/2,ii);
      r=new node((s+e)/2+1,e,ii);
      sm=l->sm+r->sm;
      cnt=l->cnt+r->cnt;
    }else{
      cnt=1;
      sm=adjlt[it][s].f.s;
      l=r=NULL;
    }
  }
  void toggle(int &iit){
    if(iit==-1)return;
    if(s==e){
      if(cnt==1)cnt=sm=0;
      else{
        cnt=1;
        sm=adjlt[it][s].f.s;
      }
      return;
    }
    if(iit<=(s+e)/2)l->toggle(iit);
    else r->toggle(iit);
    sm=l->sm+r->sm;
    cnt=l->cnt+r->cnt;
  }
  int cm(int x){//count no. of stuff strictly more than x
    if(cnt==0)return 0;
    if(s==e){
      if(adjlt[it][s].f.s>x)return 1;
      return 0;
    }
    if(x>=adjlt[it][(s+e)/2].f.s)return r->cm(x);
    else return r->cnt+l->cm(x);
  }
  int summ(int cc){//sum of first cc elements
    if(cc==0)return 0;
    if(cnt==cc)return sm;//should handle leaf nodes too
    if(l->cnt<=cc)return l->sm+r->summ(cc-l->cnt);
    return l->summ(cc);
  }
} *st[maxn];

int dp[maxn][2];//1 for destroying edge to parent
vector<int> tmp;
int deg;
void dfs(int node,int prev=-1){
  vis[node]=true;
  int it=-1;
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i].f==prev){
      it=i;
      continue;
    }
    dfs(adjl[node][i].f,node);
  }
  tmp.clear();
  dp[node][0]=0;
  for(pii x:adjl[node]){
    if(x.f==prev)continue;
    if(dp[x.f][0]>=dp[x.f][1]+x.s){//not worth destroying the edge...
      dp[node][0]+=dp[x.f][1]+x.s;
    }else{
      dp[node][0]+=dp[x.f][0];
      tmp.eb(dp[x.f][1]+x.s-dp[x.f][0]);//potential cost saved...
    }
    ; //cerr<<x.f<<' '<<dp[node][0]<<'\n';
  }
  sort(tmp.begin(),tmp.end());
  dp[node][1]=dp[node][0];
  ; //cerr<<"DP values for "<<node<<" are "<<dp[node][0]<<" "<<dp[node][1]<<'\n';
  int aa;
  if(st[node]->cnt+tmp.size()>deg){
    //cut stuff for dp[node][1]
    for(aa=0;aa<tmp.size();){
      if(st[node]->cm(tmp[aa])+(tmp.size()-aa)>deg){
        dp[node][1]+=tmp[aa++];
      }
      else break;
    }
    dp[node][1]+=st[node]->summ(st[node]->cnt-(deg-tmp.size()+aa));
  }
  if(deg==0)dp[node][0]=dp[node][1];
  else{
    deg--;
    if(st[node]->cnt+tmp.size()>deg){
      //cut stuff for dp[node][0]
      for(aa=0;aa<tmp.size();){
        if(st[node]->cm(tmp[aa])+(tmp.size()-aa)>deg){
          dp[node][0]+=tmp[aa++];
        }
        else break;
      }
      dp[node][0]+=st[node]->summ(st[node]->cnt-(deg-tmp.size()+aa));
    }
    deg++;
  }

  ; //cerr<<"DP values for "<<node<<" are "<<dp[node][0]<<" "<<dp[node][1]<<'\n';
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int a,b,c;
  cin>>n;
  vector<pair<int,pii> >edl;
  for(int i=1;i<n;i++){
    cin>>a>>b>>c;
    edl.eb(c,mp(a,b));
  }
  //build adjlt
  sort(edl.begin(),edl.end());
  for(auto x:edl){
    adjlt[x.s.s].eb(mp(x.s.f,x.f),adjlt[x.s.f].size());
    adjlt[x.s.f].eb(mp(x.s.s,x.f),adjlt[x.s.s].size()-1);
  }
  vector<pii> v;//degree, node id
  for(int i=1;i<=n;i++){
    v.eb(adjlt[i].size(),i);
    st[i]=new node(0,adjlt[i].size()-1,i);
  }
  sort(v.begin(),v.end(),greater<pii>());a=0;//next item in v to activate...

  vector<int> ans;
  for(int i=n-1;i>=0;i--){//i is hard cap on degree
    while(a<v.size() && v[a].f>i){
      //activate this node...
      act[v[a].s]=true;
      toc.push_back(v[a].s);
      for(int j=0;j<adjlt[v[a].s].size();j++){//link between v[a].s and node x.f.f
        auto x=adjlt[v[a].s][j];
        if(act[x.f.f]){
          adjl[v[a].s].eb(x.f.f,x.f.s);
          adjl[x.f.f].eb(v[a].s,x.f.s);
          //toggle the edge
          st[v[a].s]->toggle(j);
          st[x.f.f]->toggle(x.s);
        }
      }
      a++;
    }
    debl("while loop succeeded in index",i)
    for(int x:toc){
      vis[x]=false;
    }
    b=0;
    deg=i;
    for(int x:toc){
      if(vis[x])continue;
      dfs(x);
      debl("dp[x][0]",dp[x][0])
      debl("dp[x][1]",dp[x][1])
      b+=min(dp[x][0],dp[x][1]);
    }
    ans.push_back(b);
    debl("computation succeeded in index",i)
  }
  while(ans.size()>0){
    cout<<ans.back();
    ans.pop_back();
    if(ans.size()>0)cout<<' ';
    else cout<<'\n';
  }
  return 0;
}

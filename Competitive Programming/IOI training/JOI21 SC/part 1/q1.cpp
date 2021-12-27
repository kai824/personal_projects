//now ac: multiple trees
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second

int rt[200005];//cycle root...
vector<int> sks[200005];
char vis[200005];

int a[200005],h[200005],c[200005];
vector<int> adjl[200005];

int delt[200005];
map<int,int> ss[200005];//slope trick things
map<int,int>::iterator it;

int nd;
void dfs(int node,int p=-1,bool r=false){
  ss[node].clear();delt[node]=0;

  for(int x:adjl[node]){
    if(x==p)continue;
    dfs(x,node);
  }
  nd=node;
  for(int x:adjl[node]){
    if(x==p)continue;
    if(ss[x].size()>=ss[nd].size())nd=x;
  }
  if(nd!=node){
    swap(ss[nd],ss[node]);
    swap(delt[nd],delt[node]);
  }
  for(int x:adjl[node]){
    if(x==p)continue;
    for(pii hm:ss[x]){
      ss[node][hm.f]+=hm.s;
    }
    ss[x].clear();
    delt[node]+=delt[x];
  }
  //add node value...
  if(r){
    for(int x:sks[node]){
      ss[node][h[x]]+=c[x];
      ss[node][h[x]-1]-=c[x];
      delt[node]+=c[x];
    }
  }else{
    delt[node]+=c[node];

    it=ss[node].upper_bound(h[node]-1);
    int cur=0;
    while(true){
      if(it==ss[node].begin())break;
      it--;
      if(cur+it->s<=c[node]){
        cur+=it->s;
        it=ss[node].erase(it);
      }else{
        ss[node][it->f]=cur+it->s-c[node];
        break;
      }
    }
    ss[node][h[node]]+=c[node];
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin>>n;

  int tmp;
  for(int i=1;i<=n;i++){
    cin>>a[i]>>h[i]>>c[i];
    if(a[i]==i){
      rt[i]=i;
    }
    vis[i]='.';
  }
  vector<int> v;
  for(int i=1;i<=n;i++){
    if(vis[i]=='#')continue;
    v.push_back(i);vis[i]='x';
    while(true){
      if(vis[a[v.back()]]=='#')break;
      if(vis[a[v.back()]]=='x'){
        tmp=a[v.back()];
        rt[tmp]=tmp;
        while(v.back()!=tmp){
          rt[v.back()]=tmp;
          vis[v.back()]='#';
          v.pop_back();
        }
        break;
      }else{
        v.push_back(a[v.back()]);
        vis[v.back()]='x';
      }
    }

    while(v.size()>0){
      vis[v.back()]='#';
      v.pop_back();
    }
  }
  for(int i=1;i<=n;i++)if(rt[i]>0)sks[rt[i]].push_back(i);
  for(int i=1;i<=n;i++){
    if(rt[i]!=rt[a[i]] || rt[i]==0){
      if(rt[a[i]]>0)adjl[rt[a[i]]].push_back(i);
      else adjl[a[i]].push_back(i);
    }
  }

  int out=0,ans,cur;
  for(int i=1;i<=n;i++){
    if(rt[i]!=i)continue;
    dfs(i,-1,true);
    ans=delt[i],cur=delt[i];
    for(it=ss[i].end();it!=ss[i].begin();){
      it--;
      cur-=it->s;
      ans=min(ans,cur);
      //cout<<it->f<<' '<<it->s<<'\n';
    }
    out+=ans;
  }
  cout<<out;
  return 0;
}
/*
6
1 6 5
1 3 6
1 8 4
3 4 9
2 2 5
2 5 6

5
1 1 1
2 2 1
4 3 1
3 3 1
4 3 1

20
1 7 381792936
1 89 964898447
1 27 797240712
3 4 299745243
2 18 113181438
2 20 952129455
4 34 124298446
4 89 33466733
7 40 109601410
5 81 902931267
2 4 669879699
8 23 785166502
8 1 601717183
8 26 747624379
1 17 504589209
9 24 909134233
16 56 236448090
8 94 605526613
5 90 481898834
9 34 183442771

20
15 62 418848971
13 5 277275513
14 60 80376452
12 14 256845164
12 42 481331310
6 86 290168639
3 98 947342135
3 19 896070909
16 39 48034188
8 29 925729089
18 97 420006994
13 51 454182928
19 61 822405612
13 37 148425187
15 77 474094143
14 27 272926693
18 43 566552069
9 93 790433300
10 73 61654171
14 28 334498030
*/

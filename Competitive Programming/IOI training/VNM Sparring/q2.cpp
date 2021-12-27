#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

int ans=1;
const int mxn=2000005;
int l[mxn],r[mxn],v[mxn];//idk if set merging works, but :pray:
int pre[mxn],sub[mxn],nex=1;
list<pii> dq[mxn];//value, preorder label...

inline void mm(int a,int b){
  if(dq[a].size()==0)return;
  if(dq[a].back().f<dq[b].front().f){
    while(dq[a].size()>0){
      dq[b].push_front(dq[a].back());
      dq[a].pop_back();
    }
  }else{
    while(dq[a].size()>0){
      dq[b].push_back(dq[a].front());
      dq[a].pop_front();
    }
  }
}

int tmp;
void dfs(int nd){
  pre[nd]=nex++;
  int b=0;
  bool b1=false,b2=false;
  dq[nd].push_back(mp(v[nd],pre[nd]));
  if(l[nd]>0){
    dfs(l[nd]);
    if(v[l[nd]]<v[nd]){
      while(dq[l[nd]].size()>0 && dq[l[nd]].back().f>=v[nd]){
        tmp=dq[l[nd]].back().s;
        dq[l[nd]].pop_back();
        while(dq[l[nd]].size()>0 && tmp<=dq[l[nd]].back().s && dq[l[nd]].back().s<=sub[tmp])dq[l[nd]].pop_back();//check if should delete tgt
      }
      if(dq[l[nd]].size()>0){
        b=-1;
      }
      b1=true;
    }
  }
  if(r[nd]>0){
    dfs(r[nd]);
    if(v[r[nd]]>v[nd]){
      while(dq[r[nd]].size()>0 && dq[r[nd]].front().f<=v[nd]){
        tmp=dq[r[nd]].front().s;
        dq[r[nd]].pop_front();
        while(dq[r[nd]].size()>0 && tmp<=dq[r[nd]].front().s && dq[r[nd]].front().s<=sub[tmp])dq[r[nd]].pop_front();
      }

      b2=true;
      if(b==0 && dq[r[nd]].size()>0)b=1;
      else if(dq[l[nd]].size()<dq[r[nd]].size())b=1;
    }
  }
  if(b<=0){
    if(b==-1)swap(dq[nd],dq[l[nd]]);
    if(b1)mm(l[nd],nd);
    if(b2)mm(r[nd],nd);
  }else{
    swap(dq[nd],dq[r[nd]]);
    if(b2)mm(r[nd],nd);
    if(b1)mm(l[nd],nd);
  }
  if(dq[nd].size()>ans)ans=dq[nd].size();

  sub[pre[nd]]=nex-1;

  // cout<<"Set for "<<nd<<'\n';
  // for(pii x:dq[nd])cout<<x.f<<' '<<x.s<<'\t';cout<<"\n\n";
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,st;
  cin>>st>>n;
  for(int i=1;i<=n;i++){
    cin>>l[i]>>r[i]>>v[i];
  }
  dfs(1);
  cout<<ans;
}

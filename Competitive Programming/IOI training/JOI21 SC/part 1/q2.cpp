//persistent segtree with lazy propagation?!?!?!
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define eb emplace_back
#define pii pair<int,int>
#define f first
#define s second

int n;
pii vals[100005];
int lef[200005];

int par[200005][18];
void init_sts(int s,int a){//1, a
  int cur=-1;//running max on lef[i]...
  for(int i=1;i<=a;i++){
    cur=max(cur,lef[i]);
    par[i][0]=cur;
  }
  for(int i=1;i<18;i++){
    for(int j=1;j<=a;j++){
      if(par[j][i-1]==-1)par[j][i]=-1;
      else par[j][i]=par[par[j][i-1]][i-1];
    }
  }
}

int qq(int l,int r){
  int ans=0;
  for(int i=17;i>=0;i--){
    if(par[r][i]>=l){
      r=par[r][i];
      ans+=(1<<i);
    }
  }
  return ans;
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int k,a,b;
  cin>>n>>k;

  vector<pii>disc;//discretisation: raw value, index...
  for(int i=0;i<n;i++){
    cin>>a>>b;
    disc.eb(a,i*2);
    disc.eb(b,i*2+1);
  }
  sort(disc.begin(),disc.end());
  a=1;
  for(int i=0;i<2*n;i++){
    if(i>0 && disc[i].f>disc[i-1].f)a++;
    if(disc[i].s&1)vals[disc[i].s/2].s=a;
    else vals[disc[i].s/2].f=a;
  }
  for(int i=0;i<n;i++){
    //cout<<vals[i].f<<' '<<vals[i].s<<'\n';
    lef[vals[i].s]=max(lef[vals[i].s],vals[i].f);//both should be discretised...
  }
  init_sts(1,a);//initialise segtrees...

  int cur=qq(1,a),tmp;
  if(cur<k){
    cout<<-1;
    return 0;
  }//else cout<<cur<<'\n';
  set<pii> ss;ss.insert(mp(1,1));ss.insert(mp(a,a));
  set<pii>::iterator it,it2;
  bool mk[n];memset(mk,0,sizeof(mk));
  for(int i=0;i<n;i++){
    it=ss.lower_bound(vals[i]);
    it2=it--;
    if(it2==ss.end())continue;
    if(it->s<=vals[i].f && vals[i].s<=it2->f){
      tmp=cur;
      tmp+=1+(qq(it->s,vals[i].f)+qq(vals[i].s,it2->f) ) - qq(it->s,it2->f);
      if(tmp>=k){
        mk[i]=true;
        cur=tmp;
        ss.insert(vals[i]);
      }
    }
  }
  int cnt=0;
  for(int i=0;i<n && cnt<k;i++){
    if(mk[i]){
      cout<<i+1<<'\n';
      cnt++;
    }
  }
  return 0;
}
/*
5 4
1 3
2 5
8 9
6 8
10 15
*/

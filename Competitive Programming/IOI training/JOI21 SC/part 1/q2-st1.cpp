#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define eb emplace_back
#define pii pair<int,int>
#define f first
#define s second

pii vals[100005];
int rig[100005],ans[100005];


int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,k,a,b;
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
  for(int i=1;i<=a;i++)rig[i]=LLONG_MAX;
  for(int i=0;i<n;i++){
    //cout<<vals[i].f<<' '<<vals[i].s<<'\n';
    rig[vals[i].f]=min(rig[vals[i].f],vals[i].s);//both should be discretised...
  }

  vector<pii> v;int it;
  v.eb(a,0);
  for(int i=a;i>=1;i--){
    if(i==a)ans[i]=0;
    else ans[i]=ans[i+1];
    if(rig[i]==LLONG_MAX)continue;
    ans[i]=max(ans[i],ans[rig[i]]+1);
    //cout<<i<<' '<<ans[i]<<'\n';
  }
  //for(pii x:v){cout<<-x.f<<' '<<x.s<<'\n';}

  int cnt=0,cur=v.back().s;
  if(ans[1]<k){
    cout<<"-1";
    return 0;
  }
  int tt;
  for(int i=0;i<n && cnt<k;){
    if(cnt+1+ans[vals[i].s]>=k){
      cout<<i+1<<'\n';
      cnt++;
      if(cnt>=k)break;

      tt=vals[i].s;
      while(vals[i].f<tt){
        i++;
      }
    }else{
      i++;
    }
  }
  return 0;
}

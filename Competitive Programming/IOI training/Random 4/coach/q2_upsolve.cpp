#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair

int x,n,m,w,t;
int kp[200005],dp[200005];
int dea[200005];
pii ppl[200005];

inline int calc(int dj,int cur_time){
  return ((cur_time/t) + (dj<=(cur_time%t)?1:0))*w;
}

vector<pair<int,pii> >cht;

int inter(pii a,pii b){
  return (b.s-a.s)/(a.f-b.f);
}
void add_line(int m,int c){//strictly decreasing gradients...
  pii ll=mp(m,c);
  while(cht.size()>1 && inter(ll,cht.back().s)<=cht[cht.size()-2].f){
    cht.pop_back();
  }
  if(cht.size()>0)cht.back().f=inter(cht.back().s,ll);
  cht.emplace_back(LLONG_MAX,ll);
}
int query(int x){
  // int ans=1e15;
  // for(auto ll:cht){
  //   cout<<ll.f<<'\t'<<ll.s.f<<' '<<ll.s.s<<'\n';
  //   ans=min(ans,(x*ll.s.f)+ll.s.s);
  // }
  // return ans;
  pii ll=(upper_bound(cht.begin(),cht.end(),mp(x,mp(LLONG_MAX,LLONG_MAX))))->s;
  return (x*ll.f)+ll.s;
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>x>>n>>m>>w>>t;

  for(int i=0;i<n;i++){//"break points"
    cin>>kp[i];
  }
  kp[n++]=x;
  for(int i=1;i<=m;i++){//the ppl...
    cin>>ppl[i].f>>ppl[i].s;//d_j, refund cost
  }
  ppl[0]=mp(0,0);//driver...
  sort(ppl,ppl+m+1);
  //prefix sum refund costs
  for(int i=1;i<=m;i++){
    ppl[i].s+=ppl[i-1].s;
  }

  for(int i=0;i<n;i++){
    int it=upper_bound(ppl,ppl+m+1,mp(kp[i]%t,LLONG_MAX))-ppl-1;
    if(dea[it]==0)dea[it]=kp[i];
    else dea[it]=min(dea[it],kp[i]);
  }
  dp[0]=calc(0,x);
  add_line(0,dp[0]);
  for(int i=1;i<=m;i++){
    //cout<<ppl[i].s<<'\n';
    int val=dp[i-1]+calc(ppl[i].f,x);//if we don't refund...
    if(dea[i]>0){
      // for(int j=0;j<i;j++){
      //   val=min(val,dp[j]+ppl[i].s-ppl[j].s+((i-j)*(calc(ppl[i].f,dea[i]-t)) ));
      // }
      int x=calc(ppl[i].f,dea[i]-t);
      val=min(val,ppl[i].s+(i*x)+query(x) );
    }
    dp[i]=val;

    add_line(-i,dp[i]-ppl[i].s);
    // cout<<i<<' '<<dp[i]<<'\n';
  }
  cout<<dp[m];
  return 0;
}

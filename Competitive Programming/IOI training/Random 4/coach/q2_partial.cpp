#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair

int x,n,m,w,t;

int arr[200005],vals[200005];
int td[200005];//"time of death"
bool die[200005];

pii ppl[200005],kp[200005];
vector<pii> kk;

inline int calc(int dj,int cur_time){
  return (cur_time/t) + (dj<=(cur_time%t)?1:0);
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>x>>n>>m>>w>>t;

  int cost=0;

  for(int i=0;i<n;i++){//our "kill points" (+ end of journey)
    cin>>arr[i];
  }
  arr[n++]=x;
  sort(arr,arr+n);

  cost+=(x/t)+1;//for the driver
  for(int i=0;i<m;i++){//passengers...
    cin>>ppl[i].f>>ppl[i].s;

    cost+=(x/t);
    if(ppl[i].f<=(x%t))cost++;
  }
  ppl[m++]=mp(0,1e18);//bus driver moment...
  sort(ppl,ppl+m);
  for(int i=0;i<m;i++)td[i]=x;

  for(int i=0;i<n;i++){
    kp[i].f=arr[i]%t;
    kp[i].s=arr[i];
  }
  cost*=w;//base cost...
  sort(kp,kp+n);
  for(int i=0;i<n;i++){
    if(i>0 && kp[i].f==kp[i-1].f)continue;//if kp at same point, pick the earlier one will do
    kk.emplace_back(kp[i]);
  }n=kk.size();

  int nex=0;//nex on ppl array
  int mm=0;//max amt saved...
  //vals stores amount saved...
  vals[0]=0;
  for(int i=0;i<n;i++){
    // cout<<kk[i].f<<' '<<kk[i].s<<'\n';
    while(nex<m && ppl[nex].f<kk[i].f)nex++;
    //compute vals[nex-1]: array is for the sake of it...
    vals[nex-1]=0;
    int cur=0,it=nex;
    for(int j=nex-1;j>0;j--){
      //add cost saved to cur...
      if(td[j]<kk[i].s){
        break;//previous kill was earlier, and it wasn't worth it...
      }

      if(die[j]){
        cur+=(calc(ppl[j].f,x)-max(0ll,calc(ppl[j].f,kk[i].s)-1))*w;
        cur-=(calc(ppl[j].f,x)-max(0ll,calc(ppl[j].f,td[j])-1))*w;
      }else{
        cur+=(calc(ppl[j].f,td[j])-max(0ll,calc(ppl[j].f,kk[i].s)-1))*w;
        cur-=ppl[j].s;//compensation
      }
      // cout<<cur<<' '<<ppl[j].f<<' '<<ppl[j].s<<'\n';

      if(cur>vals[nex-1]){
        vals[nex-1]=cur;
        it=j;
      }
    }
    for(int j=it;j<nex;j++){
      td[j]=kk[i].s;
      die[j]=true;
    }
    // cout<<nex<<' '<<vals[nex-1]<<' '<<it<<"\n\n";

    mm+=(vals[nex-1]);
  }
  //cout<<mm<<'\n';
  cout<<cost-mm;

  return 0;
}

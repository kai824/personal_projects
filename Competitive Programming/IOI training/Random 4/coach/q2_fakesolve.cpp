#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair

int x,n,m,w,t;

int arr[200005],latest[200005];

pii ppl[200005],kp[200005];
vector<pii> kk;

inline int calc(int dj,int cur_time){
  return (cur_time/t) + (dj<=(cur_time%t)?1:0);
}

struct node{
  int s,e,v;
  int lset=-1;
  bool mark=false;
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
      v=latest[s];
    }else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
      v=min(l->v,r->v);
    }
  }
  void prop(){
    if(s==e)return;
    if(mark)l->mark=r->mark=true;
    if(lset!=-1){
      l->lset=r->lset=lset;
      l->v=r->v=lset;
      lset=-1;
    }
  }
  bool seek(int start,int tt){//to the left...
    //return true if whole range is marked...
    //cerr<<"SEEKING ON RANGE "<<s<<' '<<e<<" ATTRIBUTES "<<start<<' '<<tt<<'\n';
    if(start<s)return false;
    prop();
    if(start<e){
      if((s+e)/2<start){
        bool ans=r->seek(start,tt);
        if(ans)ans=l->seek(start,tt);
        v=min(l->v,r->v);
        return ans;
      }
      bool ans=l->seek(start,tt);
      v=min(l->v,r->v);
      return ans;
    }
    //includes whole range:
    //cout<<v<<' '<<tt<<'\n';
    if(v>=tt){//whole range is eligible!
      //cout<<"HOLY SHIT it happened "<<s<<' '<<e<<'\n';
      mark=true;
      v=lset=tt;
      return true;
    }//else cout<<"U WHAT "<<v<<' '<<tt<<'\n';
    if(s==e){
      return false;
    }
    if(r->v>=tt){
      r->lset=r->v=tt;
      bool ans=l->seek(start,tt);
      v=min(l->v,r->v);
      return ans;
    }
    else return r->seek(start,tt);
  }
  int haha(){
    if(s==e){
      //cout<<s<<' ';
      if(lset!=-1){
        int ans=(calc(ppl[s].f,x)-max(0ll,calc(ppl[s].f,v)-1))*w;//v represents the timing...
        ans-=ppl[s].s;
        //cout<<v<<'\n';
        return ans;
      }
      //cout<<"0\n";
      return 0;//0 savings...
    }
    prop();
    return l->haha()+r->haha();
  }
} *root;

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
  cost*=w;//base cost...

  latest[0]=-1;//driver...
  for(int i=1;i<m;i++){
    int cnt=calc(ppl[i].f,x);//no. of times they will drink...
    cnt-=((ppl[i].s-1)/w) +1;//ceil division...
    //it can drink at most cnt no. of times...
    if(cnt<0)latest[i]=-1;
    else{
      latest[i]=(cnt*t)+t+ppl[i].f-1;
    }
    cout<<cnt<<' '<<latest[i]<<'\t';
  }
  cout<<'\n';

  root=new node(0,m-1);

  for(int i=0;i<n;i++){
    kp[i].f=arr[i]%t;
    kp[i].s=arr[i];
  }
  sort(kp,kp+n);
  for(int i=0;i<n;i++){
    if(i>0 && kp[i].f==kp[i-1].f)continue;//if kp at same point, pick the earlier one will do
    kk.emplace_back(kp[i]);
  }n=kk.size();

  int nex=0;//nex on ppl array
  for(int i=0;i<n;i++){
    // cout<<kk[i].f<<' '<<kk[i].s<<'\n';
    while(nex<m && ppl[nex].f<kk[i].f)nex++;
    root->seek(nex-1,kk[i].s);//starting point, limit...
  }
  int mm=root->haha();
  cout<<mm<<'\n';
  cout<<cost-mm;

  return 0;
}

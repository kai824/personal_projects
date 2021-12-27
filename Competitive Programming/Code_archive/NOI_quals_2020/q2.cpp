#include "bits/stdc++.h"
using namespace std;

#define int long long

pair<int,pair<int,int> > arr[300005];

int n,d;

struct node{
  int v,lazy=0,s,e;//v includes lazy...
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    l=r=NULL;
    v=-e;//since it'll always be the downslope thing...
    //cout<<"CREATED A NEW NODE FOR RANGE "<<ss<<" to "<<ee<<'\n';
  }
  int query(int a,int b){
    return v;
  }
  void update(int a,int b,int c){//propagate the whole range from a to b, by c...
    if(a<=s && e<=b){
      if(s<e)lazy+=c;
      v+=c;
      //cout<<"lazy update on "<<s<<' '<<e<<'\n';
      return;
    }
    if(l==NULL)l=new node(s,(s+e)/2);
    if(r==NULL)r=new node((s+e)/2 + 1,e);
    if(a<=((s+e)/2))l->update(a,b,c);
    if(b>((s+e)/2))r->update(a,b,c);
    v=lazy+min(l->v,r->v);
    //cout<<"new min from "<<s<<" to "<<e<<" is "<<v<<'\n';
  }
} *root;//lazy node, lazy propagation range min segtree...


int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>d;
  int cc,ans;
  root=new node(1,d);
  ans=-root->query(1,d);
  for(int x=0;x<n;x++){
    cin>>arr[x].second.first>>arr[x].second.second>>arr[x].first;
  }
  sort(arr,arr+n,greater<pair<int,pair<int,int> > >() );
  //sort by decreasing "max fuel"

  for(int x=0;x<n;x++){//assume can now use station x...
    root->update(arr[x].second.first+1,d,arr[x].second.second);
    //cout<<arr[x].second.first+1<<' '<<d<<'\t'<<arr[x].second.second<<'\n';
    cc=-root->query(1,d);//find the amt of fuel needed when starting...
    if(cc<=arr[x].first){//must meet the max fuel rule...
      ans=min(ans,cc);
    }
  }
  /*for(int x=1;x<=d;x++){
    cout<<root->query(x,x)<<' ';
  }cout<<'\n';*/
  cout<<ans;
  return 0;
}

/*
5 100
50 30 25
50 40 25
25 25 25
75 20 25
5 5 25
*/

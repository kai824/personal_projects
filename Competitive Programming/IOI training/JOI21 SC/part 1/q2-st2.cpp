#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define eb emplace_back
#define pii pair<int,int>
#define f first
#define s second
 
pii vals[100005];
int lef[100005];
 
/*struct node{
  int s,e,v;
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    v=0;
  }
  void copy(node *t){
    v=t->v;
    l=t->l;
    r=t->r;
  }
  void update(){
    ;
  }
} *st[100005];*/
 
void init_sts(){
  ;
}
 
vector<pii> v;int it;
int qq(int l,int r){//speed up with segtree somehow later...
  v.clear();v.eb(l,0);
  for(int i=l+1;i<=r;i++){
    if(lef[i]<l)continue;
    it=upper_bound(v.begin(),v.end(),mp(lef[i],LLONG_MAX))-v.begin()-1;
    it=v[it].s+1;
    if(v.back().s>=it)continue;
    v.eb(i,it);
  }
  return v.back().s;
}
 
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
  for(int i=0;i<n;i++){
    //cout<<vals[i].f<<' '<<vals[i].s<<'\n';
    lef[vals[i].s]=max(lef[vals[i].s],vals[i].f);//both should be discretised...
  }
  init_sts();//initialise segtrees...
 
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

#include<bits/stdc++.h>
using namespace std;
#define int long long
//shouldn't need, just in case...

int eve[2000005];
list<list<int> > luol;
list<int> tmp;

bool mk[1000005];
int par[1000005],sz[1000005];
int getr(int x){
  if(par[x]==-1)return x;
  int t=getr(par[x]);
  if(mk[par[x]])mk[x]=!mk[x];
  return par[x]=t;
}

bool bruh=false;
int c,d;
void merge(int a,int b){
  //cout<<"MERGE"<<a<<' '<<b<<'\n';
  c=getr(a);d=getr(b);
  if(c==d){
    //cout<<"path1\n";
    //cout<<a<<' '<<b<<' '<<mk[a]<<mk[b]<<'\n';
    if(mk[a]==mk[b])bruh=true;
    return;
  }
  if(sz[c]<sz[d]){swap(c,d);swap(a,b);}
  par[d]=c;
  if(mk[a]==mk[b])mk[d]=true;//roots don't have marks so...
  sz[c]+=sz[d];
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin>>n;
  int a,b;
  for(int i=1;i<=n;i++){
    cin>>a>>b;
    eve[a]=i;
    eve[b]=-i;
    sz[i]=1;par[i]=-1;
  }
  vector<int> st;
  for(int i=1;i<=n+n;i++){
    if(eve[i]>0)st.push_back(eve[i]);
    else{
      for(int j=st.size()-1;j>=0;j--){
        if(st[j]==-eve[i]){
          st.erase(st.begin()+j);
          break;
        }
        merge(st[j],-eve[i]);
      }
    }
    //for(int x:st)cout<<x<<' ';cout<<'\n';
  }
  if(bruh)cout<<0;
  else{
    int ans=1;
    for(int i=1;i<=n;i++){
      if(par[i]==-1){
        ans<<=1;
        ans%=1000000007;
      }
    }
    cout<<ans;
  }
  return 0;
}

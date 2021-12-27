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
  for(int i=0;i<n;i++){
    cin>>a>>b;
    eve[a]=(i+1);
    eve[b]=-(i+1);
    par[i+1]=-1;sz[i+1]=i;
  }
  for(int i=1;i<=(n*2);i++){
    if(eve[i]>0){
      luol.push_back(*(new list<int>));
      luol.back().push_back(eve[i]);
    }else{
      eve[i]=-eve[i];
      tmp.clear();
      while(true){
        if(luol.size()==0){
          //cout<<"path 2\n";
          goto hell;
        }
        if(luol.back().back()==eve[i]){
          luol.back().pop_back();
          if(luol.back().size()==0)luol.pop_back();
          break;
        }
        merge(eve[i],luol.back().back());
        if(bruh)goto hell;
        tmp.splice(tmp.begin(),luol.back());
        luol.pop_back();
      }
      if(tmp.size()>0){
        luol.push_back(*(new list<int>));
        luol.back().splice(luol.back().begin(),tmp);
      }
    }

    /*for(auto x:luol){
      for(auto y:x)cout<<y<<' ';cout<<'\t';
    }cout<<'\n';*/
  }
  if(false){
    hell:;
    cout<<"0";
    return 0;
  }
  int ans=1;
  for(int i=1;i<=n;i++){
    if(par[i]==-1){
      ans*=2;
      ans%=1000000007;
    }
  }
  cout<<ans;
  return 0;
}

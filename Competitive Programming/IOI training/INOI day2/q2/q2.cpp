#include<bits/stdc++.h>
using namespace std;

string ss[4005];
char c[4005];
vector<pair<int,int> >vv[4005],tp[4005];

int suff[4005];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,K;
  cin>>n>>K;

  string ans="";
  for(int i=0;i<n;i++){
    cin>>ss[i];
    suff[i]=ss[i].size();
  }
  for(int i=n-2;i>=0;i--)suff[i]+=suff[i+1];

  bool ok,co;//ok, carry over...

  for(int i=1;i<=K;i++)c[i]='{';

  for(int i=0;i<n;i++){
    for(int j=0;j<ss[i].size();j++){
      co=false;
      int lo=K-(suff[i]-j-1);
      lo=max(lo,1);
      for(int k=lo;k<=K-(n-1-i);k++){//must leave enough spots behind...
        if(co){
          c[k]='z'+1;
          vv[k].clear();tp[k].clear();
        }
        ok=false;
        if(i==0 && k==1)ok=true;
        else{
          if(vv[k-1].size()>0 && vv[k-1].back().first==i-1){
            ok=true;
          }else if(tp[k-1].size()>0 && tp[k-1].back().second==j-1)ok=true;//consecutive things...
          else if(tp[k-1].size()>1 && tp[k-1][tp[k-1].size()-2].second==j-1)ok=true;
        }

        if(ok==false)continue;
        //cout<<"DEBUG"<<i<<' '<<j<<' '<<k<<'\n';
        if(ss[i][j]==c[k]){
          tp[k].emplace_back(i,j);
        }else if(ss[i][j]<c[k]){
          co=true;
          c[k]=ss[i][j];
          vv[k].clear();tp[k].clear();
          tp[k].emplace_back(i,j);
        }
      }
    }
    for(int j=1;j<=K;j++){
      for(auto x:tp[j])vv[j].push_back(x);
      tp[j].clear();
    }
    //for(int i=1;i<=K;i++)cout<<c[i];
  }
  /*for(int i=1;i<=K;i++){
    for(auto x:vv[i])cout<<x.first<<' '<<x.second<<'\n';cout<<'\n';
  }*/
  /*for(int i=1;i<=K;i++){
    if(c[i]=='{'){
      cout<<"Not ok\n";
      return 0;
    }
  }
  cout<<"Ok\n";*/

  for(int i=1;i<=K;i++)cout<<c[i];
  return 0;
}
/*
3 5
abc
xxx
aaa
*/

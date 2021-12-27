#include<bits/stdc++.h>
using namespace std;

string ss[4005];
char c;
vector<int> v,v2;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>ss[i];
  }
  string ans="z";
  for(int i=0;i<ss[n-1].size();i++){
    ans[0]=min(ans[0],ss[n-1][i]);
  }

  for(int i=n-2;i>=0;i--){
    c='z'+1;
    v.clear();
    for(int j=0;j<ss[i].size();j++){
      if(ss[i][j]<c){
        v.clear();
        v.push_back(j);
        c=ss[i][j];
      }else if(ss[i][j]==c){
        v.push_back(j);
      }
    }
    int j,chk;
    for(j=1;true;j++){
      v2.clear();
      for(int x:v){
        if(x+j<ss[i].size() && ss[i][x+j]<ans[0])v2.push_back(x);
      }
      if(v2.size()>0){
        swap(v,v2);
        chk=j+1;//confirm can length J+1
        continue;
      }

      for(int x:v){
        if(x+j<ss[i].size() && ss[i][x+j]<=ans[0])v2.push_back(x);
      }
      if(v2.size()>0)swap(v,v2);
      else break;
    }
    //stuff we want is now left in v, of length chk...
    ans=ss[i].substr(v[0],chk)+ans;
  }
  cout<<ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
typedef pair<int,int> pii;

const int mxn=500005;

vector<int> ans;
vector<pii> kek[mxn];
pii tmp;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;string s;
  cin>>n>>s;
  int cur=1,mm=1;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
      cur++;
    }else{
      kek[cur].eb(cur,1);
      cur=1;
    }
    mm=max(mm,cur);
  }
  kek[cur].eb(cur,1);

  bool b=0;
  for(int i=mm;i>1;i--){
    while(kek[i].size()>0){
      if(b==0)ans.push_back(i);
      b=(!b);

      tmp=kek[i].back();
      tmp.s++;

      kek[i].pop_back();
      kek[1+((tmp.f-1)/tmp.s)].push_back(tmp);
      // cout<<1+((tmp.f-1)/tmp.s) <<' '<<tmp.f<<' '<<tmp.s<<'\n';
    }
  }

  for(int i=1;i<=n;i++){//because ans[0] gives answer with 0 flips
    if(i>=ans.size())cout<<1;
    else cout<<ans[i];

    if(i<n)cout<<' ';
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
typedef pair<int,int> pii;

const int mxn=10000005;

int cnts[mxn];
vector<pii> rngs;

int ops(int e){//how many operations needed to get easiness<=e
  int ans=0;
  for(pii x:rngs){
    ans+=((x.f-1)/e)*x.s;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;string s;
  cin>>n>>s;
  int cur=1,mm=1;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
      cur++;
    }else{
      cnts[cur]++;
      cur=1;
    }
    mm=max(mm,cur);
  }
  cnts[cur]++;
  for(int i=1;i<=n;i++){
    if(cnts[i]>0)rngs.eb(i,cnts[i]);
  }

  cur=mm;//current easiness...

  for(int i=1;i<=n;i++){
    while(cur>1 && ops(cur-1)<=(i*2)){
      cur--;
    }
    cout<<cur<<"\n "[i<n];
  }

  return 0;
}

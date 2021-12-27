#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
typedef pair<int,int> pii;

const int mxn=500005;

vector<int> rngs;

int ops(int e){//how many operations needed to get easiness<=e
  int ans=0;
  for(int x:rngs){
    ans+=(x-1)/e;
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
      rngs.push_back(cur);
      cur=1;
    }
    mm=max(mm,cur);
  }
  rngs.push_back(cur);

  cur=mm;//current easiness...

  for(int i=1;i<=n;i++){
    if(cur>1){
      int lo=1,hi=cur,mid;
      while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(ops(mid)<=(i*2)){
          hi=mid;
        }else lo=mid+1;
      }
      cur=lo;
    }
    cout<<cur<<"\n "[i<n];
  }

  return 0;
}

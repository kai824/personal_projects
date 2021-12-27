// ans.cpp 14 Nov 18, 11:12:02 100 0 Judging completed in 2.27s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  long long tc,n,k,i,f,c;
  deque<pair<long long, long long>> d;
  cin>>tc;
  for(i=0;i<tc;i++){
    cin>>n>>k;
    d.push_back({n,1});
    while(k>0){
      f=d.front().first;
      c=d.front().second;
      if(k<=c){
        cout<<"Case #"<<i+1<<": "<<f/2<<' '<<(f-1)/2<<'\n';
        break;
      }
      d.pop_front();
      f--;
      //Breaking into left and right sections
      if(d.back().first==(f+1)/2){
        d.back().second+=c;
      }
      else{
        d.push_back({(f+1)/2,c});
      }
      if(d.back().first==f/2){
        d.back().second+=c;
      }
      else {
        d.push_back({f/2,c});
      }
      k-=c;
    }
    d.clear();
  }
  return 0;
}
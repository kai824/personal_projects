// ans.cpp 20 Nov 20, 16:18:01 100 0.51 Judging completed in 9.27s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main (){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x,ans=0;
  int t;
  unordered_set<int> s;
  cin >> x; 
  for (int i=0; i<x; i++){
    cin >> t;
    if(s.find(t)==s.end()){
        ans++;
    s.insert(t);
    }
  }
  cout << ans;
}
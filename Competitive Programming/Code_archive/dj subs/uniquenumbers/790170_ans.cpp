// ans.cpp 20 Nov 20, 16:18:53 100 0.5 Judging completed in 5.074s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main (){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x;
  int t;
  unordered_set<int> s;
  cin >> x; 
  for (int i=0; i<x; i++){
    cin >> t;
    s.insert(t);
  }
  cout << s.size();
}
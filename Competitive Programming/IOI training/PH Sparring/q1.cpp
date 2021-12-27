#include<bits/stdc++.h>
using namespace std;

int score;

int q;
string res;
vector<int> v;

int query(string ss){
  cout<<ss<<'\n';
  cin>>q;
  cin>>res;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,a,b;string s;
  cin>>q;
  while(q>0){
    cin>>m>>a>>b>>n>>s;
    v.clear();
    for(int i=0;i<n;i++){
      if(s[i]=='?'){
        v.push_back(i);
        s[i]='Y';
      }
    }
    int cur=query(s);
    score++;
  }
  end:;
  cout<<"DONE\n";
  cout<<score;
  return 0;
}

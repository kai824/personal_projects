// messy.cpp 14 Jul 20, 10:06:27 100 0 Judging completed in 8.167s on AWS Oregon.
#include "messy.h"
#include "bits/stdc++.h"
using namespace std;

#define mkp make_pair
map<pair<int,int>,vector<int> > mp;
vector<int> tmp,tmp2;
vector<int> restore_permutation(int n, int w, int r) {//length n, rest don't matter
  string s="";
  for(int x=0;x<n;x++)s+="1";
  int n2=n;//current set where you need find which parts is left half and which parts is right half...
  while(n2>1){
    for(int i=0;i<n;i+=n2){
      for(int j=0;j<n2;j++){
        s[i+j]='0';
      }
      for(int j=0;j<n2/2;j++){
        s[i+j]='1';
        //cout<<s<<'\n';
        add_element(s);
        s[i+j]='0';
      }
      for(int j=0;j<n2;j++){
        s[i+j]='1';
      }
    }
    n2/=2;
  }
  compile_set();
  n2=n;
  for(int x=0;x<n;x++)tmp.push_back(x);
  mp[mkp(0,n-1)]=tmp;
  while(n2>1){
    for(int i=0;i<n;i+=n2){
      tmp.clear();tmp2.clear();
      for(int j=0;j<mp[mkp(i,i+n2-1)].size();j++){
        s[mp[mkp(i,i+n2-1)][j]]='0';
      }
      for(int j=0;j<mp[mkp(i,i+n2-1)].size();j++){
        s[mp[mkp(i,i+n2-1)][j]]='1';
        //cout<<"here:"<<s<<'\n';
        if(check_element(s)){
          tmp.push_back(mp[mkp(i,i+n2-1)][j]);//left half
        }else tmp2.push_back(mp[mkp(i,i+n2-1)][j]);//right half...
        s[mp[mkp(i,i+n2-1)][j]]='0';
      }
      mp[mkp(i,i+(n2/2)-1)]=tmp;
      mp[mkp(i+(n2/2),i+n2-1 )]=tmp2;
      for(int j=0;j<mp[mkp(i,i+n2-1)].size();j++){
        s[mp[mkp(i,i+n2-1)][j]]='1';
      }
    }
    n2/=2;
  }
  //check_element("0");
  vector<int> ans;
  for(int x=0;x<n;x++)ans.push_back(0);
  for(auto it=mp.begin();it!=mp.end();it++){
    if(it->first.first==it->first.second){
      if(it->second.size()==0){
        //cerr<<"LEGIT BEEG GAYY SIAH!!\n";
      }
      //ans[it->first.first]=it->second[0];
      ans[it->second[0]]=it->first.first;
    }
  }
  return ans;
}

/*
4 100 100
2 1 3 0
*/
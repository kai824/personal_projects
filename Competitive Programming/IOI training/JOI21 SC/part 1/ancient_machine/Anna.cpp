#include "Anna.h"
#include <bits/stdc++.h>
using namespace std;

void Anna(int n,vector<char> s) {
  for(int i=0;i<n;i++){
    if(s[i]=='X'){
      Send(0);Send(0);
    }else if(s[i]=='Y'){
      Send(0);Send(1);
    }else{
      Send(1);Send(1);
    }
  }
}

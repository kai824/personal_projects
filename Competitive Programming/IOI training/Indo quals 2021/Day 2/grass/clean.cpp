#include "grass.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

vector<ll> simulate2(int n,int h,int m, vector<char> events, vector<int> x) {//m events
  ll arr[n];memset(arr,0,sizeof(arr));
  vector<ll> ans;
  ll sum=0;
  for(int i=0;i<m;i++){
    if(events[i]=='N'){//grow...
      for(int j=0;j<n;j++){
        arr[j]+=x[i];
        arr[j]=min(arr[j],(ll)h);
      }
    }else if(events[i]=='L'){//trim stuff on the left...
      for(int j=0;j<x[i];j++)arr[j]=0;
    }else if(events[i]=='D'){//right...
      for(int j=0;j<x[i];j++)arr[n-1-j]=0;
    }else if(events[i]=='S'){//cap them at height S...
      for(int j=0;j<n;j++)arr[j]=min(arr[j],(ll)x[i]);
    }else{//query
      sum=0;
      for(int j=0;j<n;j++)sum+=arr[j];
      ans.push_back(sum);
    }
  }

  return ans;
}

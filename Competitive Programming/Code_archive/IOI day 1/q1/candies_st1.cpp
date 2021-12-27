#include "candies.h"
#include<bits/stdc++.h>
using namespace std;

#define lnt long long
const lnt inf=1e17;
typedef pair<lnt,lnt> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back


vector<int> distribute_candies2(vector<int> c, vector<int> l,
                                    vector<int> r, vector<int> v) {
    int n=c.size();
    vector<int> ans;
    for(int i=0;i<n;i++)ans.push_back(0);

    int q=l.size();
    for(int i=0;i<q;i++){
      for(int j=l[i];j<=r[i];j++){
        ans[j]+=v[i];
        ans[j]=max(ans[j],0);
        ans[j]=min(ans[j],c[j]);
      }
    }
    return ans;
}

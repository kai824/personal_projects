// ans.cpp 7 Mar 20, 12:42:34 7 0.12 Judging completed in 3.619s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;
#define int long long

int n,k,a,ans;
vector<int> h;


int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
		cin>>n>>k;
		for(int x=0;x<n;x++){
			cin>>a;
			if(h.size()==0 || h.back()!=a){
				h.push_back(a);
				if(a!=0)ans++;
			}
		}

		cout<<ans<<'\n';
    return 0;
}
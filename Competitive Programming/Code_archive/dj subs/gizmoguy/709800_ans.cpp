// ans.cpp 7 Mar 20, 12:47:26 7 0.12 Judging completed in 3.655s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;
#define int long long

int n,k,a,ans,c1,c2;
vector<int> h;


int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
		cin>>n>>k;
		for(int x=0;x<n;x++){
			cin>>a;
			if(h.size()==0 || h.back()!=a){
				h.push_back(a);
				if(a==0){
				    if(c1+c2>0){
				        ans+=min(c1,c2)+1;
				    }
				    c1=c2=0;
				}else{
				    if(a==1)c1++;
				    else c2++;
				}
			}
		}
		if(c1+c2>0)ans+=min(c1,c2)+1;

		cout<<ans<<'\n';
    return 0;
}
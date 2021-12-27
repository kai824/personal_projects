// ans.cpp 20 Oct 17, 12:31:01 38 1.01 Judging completed in 8.476s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc, n, m,u;
	vector<int>s;
	cin>>tc;
	while (tc--){
	    s.clear();
		cin>>n>>m;
		bitset<105000000> sieve;
		for (int v=0;v<=n;++v) {
			sieve[v]=0;
		}
		for(int x=2;x<=n;x++){
		    if(sieve[x]==0){
		        s.push_back(x);
		        u=x*2;
		        while(u<=n){
		            sieve[u]=1;
		            u+=x;
		        }
		    }
		}
		if (s.size()<m)printf("-1\n");
		else {
			reverse(s.begin(),s.end());
			swap(s[0],s[m-1]);
			cout<<s[0]<<'\n';
		}
	}
}
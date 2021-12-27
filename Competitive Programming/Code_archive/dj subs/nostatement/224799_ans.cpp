// ans.cpp 20 Oct 17, 11:43:08 32 1 Judging completed in 7.58s on AWS Oregon.
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
		bitset<10000005> sieve;
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
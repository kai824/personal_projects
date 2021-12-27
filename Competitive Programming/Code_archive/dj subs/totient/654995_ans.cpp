// ans.cpp 18 Dec 19, 16:53:04 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool valid[1000005];
long long phi[1000005];
void computeTotient(int n) 
{
    for (int i=1; i<=n; i++) 
        phi[i] = i;
    for (int p=2; p<=n; p++){
        if (phi[p] == p){ 
            phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p){
                phi[i] = (phi[i]/p) * (p-1); 
            } 
        } 
    }
}
int main() {
    ll n,u,ans=0;
    cin>>n;
    if(x>1000000){
        while(true){};
    }
	for(int x=1;x<=n;x++){
		if(valid[x]==true)continue;
		u=x*x;
		while(u<=n){
			valid[u]=true;
			u*=x;
			if(x==1)break;
		}
	}
	computeTotient(n);
	for(int x=1;x<=n;x++){
		u=phi[x];
		if(valid[u]){
			ans+=phi[x];
			ans%=1000000007;
		}
	}
	cout<<ans;
    return 0;
}
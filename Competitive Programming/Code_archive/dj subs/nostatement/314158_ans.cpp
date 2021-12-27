// ans.cpp 6 Jan 18, 22:39:47 80 0.34 Judging completed in 4.367s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,i1;
	bitset<20000001>arr;
	vector<int>primes;
    arr[0]=1;
    arr[1]=1;
    for (i=2;i<20000001;i++){
    	if (arr[i]==0){
    		primes.push_back(i);
    		for (i1=i+i;i1<20000001;i1+=i){
    			arr[i1]=1;
    		}
    	}
    }
	int tc, n, m,index;
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		if (n<20000001){
			auto it=upper_bound(primes.begin(),primes.end(),n);
			if (it==primes.begin()){
				cout<<"-1\n";
				continue;
			}
			it--;
			index=it-primes.begin();
			index-=m;
			index++;
			if (index<0)cout<<"-1\n";
			else cout<<primes[index]<<'\n';
			
		}
		else {
			cout<<n<<'\n';
		}
		
		
		
	}
}
// ans.cpp 16 Oct 17, 12:01:25 100 0 Judging completed in 5.948s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	unsigned long long N, M, res; cin >> N >> M;
	if (N % 3 == 0){
		res = (N)*(N+1)/6;
		res = (res%M * ((N+2)%M))%M;
		cout << res << '\n';
	}else if (N % 3 == 1){
		res = (N+1)*(N+2)/6;
		res = (res%M * ((N)%M))%M;
		cout << res << '\n';
	}else{
		res = (N)*(N+1)/6;
		res = (res%M * ((N+2)%M))%M;
		cout << res << '\n';
	}
}
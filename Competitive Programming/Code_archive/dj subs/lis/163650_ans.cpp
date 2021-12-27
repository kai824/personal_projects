// ans.cpp 19 Nov 16, 14:37:18 100 0.04 Judging completed in 3.609s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int N, O[10005], PE[10005];
int main() {
	cin >> N;
	for (int i=1;i<=N;i++)cin>>O[i];

	int lis=1;
	PE[1]=1;
	for (int i=2;i<=N;i++){
		PE[i] = 1;
		for (int j=1;j<i;j++){
			if (O[j]<O[i]) {
				PE[i]=max(PE[i],PE[j]+1);
			}
		}
		lis = max(lis, PE[i]);
	}
	cout << lis << "\n";
}
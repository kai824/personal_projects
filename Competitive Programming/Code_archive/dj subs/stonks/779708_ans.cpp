// ans.cpp 9 Nov 20, 14:47:11 100 0.2 Judging completed in 6.625s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	long long cnt[n],price[n];
	for(int i=0;i<n;i++)cin>>cnt[i];
	for(int i=0;i<n;i++)cin>>price[i];
	for(int i=n-1;i>=0;i--)if(i!=n-1)price[i]=max(price[i],price[i+1]);
	long long sum=0;
	for(int i=0;i<n;i++)sum+=price[i]*cnt[i];
	cout<<sum;
}
// ans.cpp 9 Nov 20, 14:46:41 35 1.01 Judging completed in 7.884s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
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
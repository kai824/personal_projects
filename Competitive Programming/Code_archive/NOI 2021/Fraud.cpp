#include<bits/stdc++.h>
using namespace std;

#define no() cout<<"NO\n";
typedef long double ld;

int a[300005],b[300005];
ld smol,big;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	smol=-1e9;big=1e9;//x=[smol,big]*y...
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i+1<n;i++){
		if(a[i]>a[i+1] && b[i]>b[i+1])continue;
		if(a[i]<=a[i+1] && b[i]<=b[i+1]){
			no();
			return 0;
		}
		if(a[i]>a[i+1]){
			if(b[i]<b[i+1])smol=max(smol,ld(b[i+1]-b[i])/ld(a[i]-a[i+1]));
		}else if(a[i]<a[i+1]){
			if(b[i]>b[i+1])big=min(big,ld(b[i]-b[i+1])/ld(a[i+1]-a[i]));
		}
		//cout<<smol<<' '<<big<<'\n';
	}
	if(smol<big)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}

// ans.cpp 28 Dec 19, 17:29:32 0 0.38 Judging completed in 4.55s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[1000005],mod=1e9+7;
ll cur,sub;

int convert(string a){
    int ans=0;
    for(int x=0;x<a.length();x++){
        ans*=10;ans+=a[x]-'0';
    }
    return ans;
}

string tos(int a){
	string ans="", t=" ";
	while(a>0){
		t[0]=(a%10)+'0';
		ans+=t;
		a/=10;
	}
	return ans;//reverses it too...
}

ll main2(string a,string c) {
    int n,aa,bb;
    long long ans=0;
    //cin>>n;
    //cin>>a>>c;
    if(a.length()<=7){
        aa=convert(a);
        for(int x=0;x<=aa;x++){
            if(c>=tos(x)){
				ans++;
			}
        }
		return ans;
		//cout<<ans;
    }
}

int main() {
    int n;
	string a,b;
	cin>>n>>a>>b;
	//cout<<main2(a,b)<<'\n';
	arr[0]=0;
	for(int x=1;x<n;x++){
		arr[x]=arr[x-1]*10;
		arr[x]+=a[x-1]-'0';
		arr[x]%=mod;
	}
	cur=1+arr[n-1]*10+a[n-1]-'0';
	cur%=mod;//subtract from this...
	for(int x=0;x<n;x++){
		sub=('9'-b[x])*(arr[n-1-x]);
		if(b[x]<=a[n-x-1] && (n-1-x==0 || arr[n-1-x]!=0) ){
			sub+=a[n-x-1]-b[x];
		}
		cout<<'9'-b[x]<<' '<<arr[n-1-x]<<' '<<sub<<'\n';
		cur+=2*mod-sub;
		cur%=mod;
	}
	cur+=mod;cur%=mod;
	cout<<cur;
    return 0;
}
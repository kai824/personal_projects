// ans.cpp 2 Dec 19, 10:55:34 100 0 Judging completed in 3.311s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[500];
int main() {
    //ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,cur=1,nex=0,ans=0;
    cin>>n;
    while(cur<n){
        nex++;
        cur*=nex;
    }
    while(true){
        if(cur<=n){
			ans=max(ans,nex);
			arr[nex]=n/cur;
			n%=cur;
            if(n==0)break;
        }
        cur/=nex;nex--;
    }
    cout<<ans<<'\n';
	for(int x=1;x<=ans;x++){
		cout<<arr[x];
		if(x<ans)cout<<' ';
	}
    return 0;
}
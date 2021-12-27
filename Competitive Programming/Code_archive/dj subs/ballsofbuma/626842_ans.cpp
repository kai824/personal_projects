// ans.cpp 4 Dec 19, 10:28:28 100 0 Judging completed in 3.608s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a;
    cin>>a;
	if(a.length()<3){
		cout<<0;return 0;
	}
    int p1=0,p2=a.length()-1;
    int cnt1,cnt2;
    while(p1<p2){
        if(a[p1]!=a[p2]){
			cout<<0;
			return 0;
		}
		cnt1=cnt2=1;
		while(p1+1<a.length() && a[p1]==a[p1+1]){
			cnt1++;p1++;
		}
		while(p2-1>=0 && a[p2]==a[p2-1]){
			cnt2++;p2--;
		}
		if(p2<=p1){
			if(p1-p2+1<2)cout<<0;
			else cout<<p1-p2+2;
			return 0;
		}
		if(cnt1+cnt2<3){
			cout<<0;
			return 0;
		}
		p1++;p2--;
    }
    cout<<0;
    return 0;
}
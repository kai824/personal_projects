// ans.cpp 2 Dec 19, 11:06:03 87.5 0.82 Judging completed in 4.415s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
string arr[505];
bool broke=false;
int cnt1[27],cnt2[27];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a;
	cin>>n>>k;
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x==y)continue;
			for(int i=0;i<27;i++){
				cnt1[i]=cnt2[i]=0;
			}
			a=0;
			for(int i=0;i<n;i++){
				if(arr[x][i]!=arr[y][i]){
					a++;
					cnt1[arr[x][i]-'a']++;
					cnt2[arr[y][i]-'a']++;
				}
			}
			if(a>k)continue;
			broke=false;
			for(int i=0;i<27;i++){
				if(cnt1[i]!=cnt2[i]){
					broke=true;
					break;
				}
			}
			if(broke)continue;
			cout<<"DA";
			return 0;
		}
	}
	cout<<"NE";
    return 0;
}
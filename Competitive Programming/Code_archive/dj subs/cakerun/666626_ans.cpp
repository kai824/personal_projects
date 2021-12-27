// ans.cpp 28 Dec 19, 15:06:58 6 3 Judging completed in 8.56s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int arr[500005];

bool masked[320];//lazy update
map<int,int> mps[320];//sqrt decomp

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,a,b,c,d,ans;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	for(int x=n-1;x>=0;x--){
		mps[x/320][arr[x]]=x;
	}
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b>>c>>d;
		b--;c--;
		if(a==1){//query...
			ans=INT_MAX;
			for(int i=b;i<=c;i++){
				if(i%320 == 0 && i+319<=c){//at the start of a bucket...
					if(mps[i/320].find(d)!=mps[i/320].end()){
						ans=mps[i/320][d];
						break;
					}
					i+=319;//let the for loop do the extra one...
					continue;
				}
				if(arr[i]==d){
					ans=i;break;
				}
			}
			if(ans==INT_MAX)cout<<"-1\n";
			else cout<<ans+1<<'\n';
		}else{
			for(int i=b;i<=c;i++){
				if(i%320 == 0 && i+319<=c){
					masked[i/320]=true;
					mps[i/320].clear();
					mps[i/320][d]=i-(i%320);
					continue;
				}
				if(masked[i/320]==true){
					for(int j=320*(i/320);j<320*(1+i/320);j++){
						arr[j]=mps[i/320].begin()->first;
					}
					masked[i/320]=false;
				}
				arr[i]=d;
			}
			if(b%320 == 0 && b+319<=c){//starts at start of bucket...
			}else{
				mps[b/320].clear();
				for(int j=320*(1+b/320)-1;j>=320*(b/320);j--){
					mps[b/320][arr[j]]=j;
				}
			}
			if(masked[c/320]==false){
				mps[c/320].clear();
				for(int j=320*(1+c/320)-1;j>=320*(c/320);j--){
					if(arr[j]==0)continue;//cost shouldn't be 0
					mps[c/320][arr[j]]=j;
				}
			}
		}
	}
	return 0;
}
/*
5
1 1
1 2
1 3
2 4
2 5
*/
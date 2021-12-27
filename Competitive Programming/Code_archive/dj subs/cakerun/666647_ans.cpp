// ans.cpp 28 Dec 19, 15:11:38 6 3.03 Judging completed in 8.61s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

//static int SQ=708;
#define SQ 708

int arr[500005];

bool masked[SQ];//lazy update
map<int,int> mps[SQ];//sqrt decomp

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,a,b,c,d,ans;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	for(int x=n-1;x>=0;x--){
		mps[x/SQ][arr[x]]=x;
	}
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b>>c>>d;
		b--;c--;
		if(a==1){//query...
			ans=INT_MAX;
			for(int i=b;i<=c;i++){
				if(i%SQ == 0 && i+SQ-1<=c){//at the start of a bucket...
					if(mps[i/SQ].find(d)!=mps[i/SQ].end()){
						ans=mps[i/SQ][d];
						break;
					}
					i+=SQ-1;//let the for loop do the extra one...
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
				if(i%SQ == 0 && i+SQ-1<=c){
					masked[i/SQ]=true;
					mps[i/SQ].clear();
					mps[i/SQ][d]=i-(i%SQ);
					continue;
				}
				if(masked[i/SQ]==true){
					for(int j=SQ*(i/SQ);j<SQ*(1+i/SQ);j++){
						arr[j]=mps[i/SQ].begin()->first;
					}
					masked[i/SQ]=false;
				}
				arr[i]=d;
			}
			if(b%SQ == 0 && b+SQ-1<=c){//starts at start of bucket...
			}else{
				mps[b/SQ].clear();
				for(int j=SQ*(1+b/SQ)-1;j>=SQ*(b/SQ);j--){
					mps[b/SQ][arr[j]]=j;
				}
			}
			if(masked[c/SQ]==false){
				mps[c/SQ].clear();
				for(int j=SQ*(1+c/SQ)-1;j>=SQ*(c/SQ);j--){
					if(arr[j]==0)continue;//cost shouldn't be 0
					mps[c/SQ][arr[j]]=j;
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
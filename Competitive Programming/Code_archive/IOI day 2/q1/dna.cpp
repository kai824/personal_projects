#include "dna.h"
#include<bits/stdc++.h>
using namespace std;

#define lint long long
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair

int n;

int lps[100005][3];//no. of this letter in S1 - count in S2...
int pps[100005][6];//ab,ac,ba,bc,cb,ca...

void init(string a, string b){
	n=a.length();
	assert(a.length()==b.length());
	for(int i=1;i<=n;i++){
		int x,y;
		if(a[i-1]=='A')x=0;
		else if(a[i-1]=='T')x=1;
		else x=2;
		if(b[i-1]=='A')y=0;
		else if(b[i-1]=='T')y=1;
		else y=2;

		for(int j=0;j<3;j++){
			lps[i][j]=lps[i-1][j];
		}
		lps[i][x]++;lps[i][y]--;

		for(int j=0;j<6;j++)pps[i][j]=pps[i-1][j];
		if(x==y)continue;
		if(x==0){
			if(y==1)y=0;//ab
			else y=1;//ac
		}else if(x==1){
			if(y==0)y=2;//ba
			else y=3;//bc
		}else{
			if(y==0)y=5;//ca
			else y=4;//cb
		}
		pps[i][y]++;//stored as temporary variable...
	}

	for(int j=0;j<3;j++)lps[n+1][j]=lps[n][j];
	for(int j=0;j<6;j++)pps[n+1][j]=pps[n][j];
}

int get_distance(int x, int y) {
	x++;y++;//make 0-indexed...
	for(int j=0;j<3;j++){
		if(lps[x-1][j]!=lps[y][j])return -1;//diff no. of some letter...
	}
	int ans=0;
	int arr[6];
	for(int j=0;j<6;j++){
		arr[j]=pps[y][j]-pps[x-1][j];
	}

	int tmp;
	tmp=min(arr[0],arr[2]);//ab ba
	ans+=tmp;arr[0]-=tmp;arr[2]-=tmp;
	tmp=min(arr[1],arr[5]);//ac ca
	ans+=tmp;arr[1]-=tmp;arr[5]-=tmp;
	tmp=min(arr[3],arr[4]);//bc cb
	ans+=tmp;arr[3]-=tmp;arr[4]-=tmp;

	// for(int j=0;j<6;j++)cout<<arr[j]<<' ';cout<<'\n'; //arr[0 3 5] should be equal, and arr[1 2 4] also...
	tmp=0;
	for(int j=0;j<6;j++)tmp+=arr[j];
	ans+=(tmp/3)*2;//i think?
	return ans;
}

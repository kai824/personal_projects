#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define rng rnd.next
//atoi exists...
//rng(L,R) generates int in range [L,R]

bool part[500005];
vector<int> partitions;

int main(int argc, char *argv[]) {//args: N, number of partitions (if any limit)
	registerGen(argc, argv, 1);

  ios_base::sync_with_stdio(false);cout.tie(0);

	//argv[0] is command, so start from argv[1]
	int n=atoi(argv[1]);
	int p_cnt;

	if(argv[2][0]=='-'){
		p_cnt=rng(0,n-1);
	}else p_cnt=atoi(argv[2]);
	p_cnt=min(p_cnt,n-1);

	int tmp;
	if(p_cnt<n/2){
		for(int i=0;i<p_cnt;i++){
			tmp=rng(1,n-1);
			while(part[tmp])tmp=rng(1,n-1);
			part[tmp]=true;
		}
	}else{
		for(int i=p_cnt;i<n-1;i++){
			tmp=rng(1,n-1);
			while(part[tmp])tmp=rng(1,n-1);
			part[tmp]=true;
		}
		for(int i=1;i<=n-1;i++){
			part[i]=(!part[i]);
		}
	}

	cout<<n<<'\n';
	int cur=rng(0,1);
	for(int i=1;i<=n;i++){
		cout<<cur;
		if(part[i])cur=(1-cur);
	}
	cout<<'\n';

	return 0;
}

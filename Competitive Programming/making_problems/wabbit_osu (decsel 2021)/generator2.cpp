//Attempt to break n sqrt n solution...

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define rng rnd.next
//atoi exists...
//rng(L,R) generates int in range [L,R]



int main(int argc, char *argv[]) {//args: N, number of partitions (if any limit)
	registerGen(argc, argv, 1);

  ios_base::sync_with_stdio(false);cout.tie(0);

	//argv[0] is command, so start from argv[1]
	int n=atoi(argv[1]);

	vector<int> v;//partition_lengths...
	int sum=0;
	for(int i=1;sum+i<n;i++){
		sum+=i;
		v.push_back(i);
		if(rng(1,10)==1)i++;//randomly skip some lengths cos why not...
	}
	v.push_back(n-sum);
	shuffle(v.begin(),v.end());

	cout<<n<<'\n';
	int cur=rng(0,1);
	for(int x:v){
		for(int j=0;j<x;j++)cout<<cur;
		cur=(1-cur);
	}
	cout<<'\n';

	return 0;
}

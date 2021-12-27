#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {//args: N, number of partitions (if any limit)
	ios_base::sync_with_stdio(false);cout.tie(0);
 
	int n=atoi(argv[1]),k=atoi(argv[2]);
 
	vector<int> v;//partition_lengths
	
	int sum=0;
	for(int i=1;i<=k;i++){
		sum+=i;
		v.push_back(i);
	}
	
	v.push_back(n-sum);
	shuffle(v.begin(),v.end());
 
	cout<<n<<'\n';
	int cur=rnd.next(2);
	for(int x:v){
		for(int j=0;j<x;j++)cout<<cur;
		cur=(1-cur);
	}
	cout<<'\n';
 
	return 0;
}


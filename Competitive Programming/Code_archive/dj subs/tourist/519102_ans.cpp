// ans.cpp 28 Apr 19, 15:29:31 1 0.19 Judging completed in 4.734s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,k,max_h=0,cur_h=0,nex=0;//maximal happiness
	cin>>n>>k;
	long long h[n+5];
	bool broke=false;
	priority_queue<long long,vector<long long>, greater<long long> > pq;
	if(n==1)while(true){};
	for(int x=0;x<n;x++){
		cin>>h[x];
		if(k>=2){
			if(x==0)k-=1;
			else k-=2;
			cur_h+=h[x];
			nex=x+1;
			pq.push(h[x]);
			//cout<<"pushed "<<h[x]<<'\n';
		}
	}
	max_h=max(max_h,cur_h);
	//cout<<max_h<<'\n';
	while(nex<n){
		k-=2;
		cur_h+=h[nex];
		pq.push(h[nex]);
		//cout<<"pushed "<<h[nex]<<'\n';
		nex++;
		while(k<0){
		    if(pq.empty()){
		        broke=true;
		        //broke from loop
		        //broke since no coins left
		        //can't travel so far
		        break;
		    }
			cur_h-=pq.top();
			//cout<<"popped "<<pq.top()<<'\n';
			pq.pop();
			k+=1;
		}
		if(broke)break;
		max_h=max(max_h,cur_h);
		//cout<<"cur is "<<cur_h<<'\n';
	}
	cout<<max_h;
    return 0;
}
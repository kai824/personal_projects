#include "seedflare.h"
#include <bits/stdc++.h>
using namespace std;

vector<int>v,a;
bool cmp(int a,int b){
	assert(a!=b);
	assert(v.size()==2);
	v[0]=a;v[1]=b;
	if(SeedFlare(v)==0){
		return true;
	}else return false;
}
vector<int> ha;
void srt(int a,int b){
	if(a==b)return;
	int m=(a+b)/2;
	srt(a,m);srt(m+1,b);

	ha.clear();
	int p1=a,p2=m+1;
	while(p1<=m || p2<=b){
		if(p1>m){
			ha.push_back(::a[p2++]);
		}else if(p2>b){
			ha.push_back(::a[p1++]);
		}else{
			if(cmp(::a[p1],::a[p2]))ha.push_back(::a[p1++]);
			else ha.push_back(::a[p2++]);
		}
	}
	for(int i=0;i<ha.size();i++){
		::a[a+i]=ha[i];
	}
}

vector<int> SortFlowers(int n) {
	a.resize(n);
	v.resize(2);
	for (int i = 1; i <= n; i++) a[i-1] = i;
	srt(0,n-1);

	// for(int x:a)cout<<x<<' ';
	return a;
}

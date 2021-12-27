#include "Device.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[250005];
void InitDevice(){
	cnt[0]=0;
	for(int i=1;i<250001;i++){
		cnt[i]=cnt[i-1]+(250001-i);
	}
}
void unpack(ll x,int&a, int&b){
	for(int i=0;i<10;i++){//check smol numbers manually...
		if(x>=cnt[i]){
			a=i;
			b=x-cnt[i];
		}else break;
	}
	a=upper_bound(cnt,cnt+250001,x)-cnt-1;
	b=x-cnt[a]+a;
	//cout<<x<<' '<<a<<' '<<b<<'\n';
}

int Answer(long long s, long long t){
	int p1,p2,s1,s2;
	unpack(s,p1,s1);
	unpack(t,p2,s2);
	if(p1<p2 && p2<=s1)return 1;
	if(p2<p1 && p1<=s2)return 0;
	return 2;
}

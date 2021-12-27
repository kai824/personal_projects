#include "dungeons.h"
#include<bits/stdc++.h>
using namespace std;

#define lnt long long
typedef pair<lnt,lnt> pii;
#define f first
#define s second
#define mp make_pair

const int mxn=400005;

lnt thresh;
lnt cyc[mxn];//how much to gain from 1 lose cycle...
lnt ww[mxn];
pii lpar[mxn][20];//same thing but if you lose: amt gained, node...
char vis[mxn];

bool db=false;

void init(int n, vector<int> s, vector<int> p, vector<int> w, vector<int> l){//subtask 3...
	thresh=s[0];
	for(int i=0;i<n;i++){
		if(w[i]==n)w[i]=-1;
		if(l[i]==n)l[i]=-1;
		lpar[i][0]=mp(p[i],l[i]);
		vis[i]='.';
	}
	ww[n]=0;
	ww[n-1]=thresh;
	for(int i=n-2;i>=0;i--){
		ww[i]=thresh+ww[w[i]];
	}
	for(int i=1;i<20;i++){//build 2kd
		for(int j=0;j<n;j++){
			if(lpar[j][i-1].s==-1)lpar[j][i]=lpar[j][i-1];
			else lpar[j][i]=mp(lpar[lpar[j][i-1].s][i-1].f+lpar[j][i-1].f,lpar[lpar[j][i-1].s][i-1].s);
		}
	}
	vector<int> v;

	for(int i=0;i<n;i++){
		if(vis[i]!='.')continue;
		int nd=i,prev=-1;
		lnt sum=0;


		do{
			v.push_back(nd);
			if(db)cerr<<"Looping on "<<nd<<'\n';
			vis[nd]='T';
			sum+=p[nd];//find total strength gained...
			prev=nd;nd=l[nd];
		}while(nd!=-1 && vis[nd]=='.');
		sum=0;
		for(int i=v.size()-1;i>=0;i--){
			sum+=p[v[i]];
			if(v[i]==nd)break;
			if(i==0)sum=-1;
		}
		if(db)cerr<<"LINE 53 "<<sum<<' '<<nd<<'\n';
		if(nd==-1 || vis[nd]=='#')sum=-1;
		while(v.size()>0){
			cyc[v.back()]=sum;
			vis[v.back()]='#';
			if(v.back()==nd)break;
			v.pop_back();
		}
		while(v.size()>0){
			vis[v.back()]='#';
			cyc[v.back()]=-1;
			v.pop_back();
		}
		//for(int x:v)cyc[x]=sum;
	}
	for(int i=0;i<n;i++)if(cyc[i]==0)cyc[i]=-1;;
}

lnt simulate(int x, int zz){
	lnt z=zz;
	if(z<thresh && cyc[x]!=-1)z=thresh-( (thresh-z)%cyc[x]);
	if(z<thresh){
		if(db)cerr<<"After looping: "<<z<<'\n';
		for(int i=19;i>=0;i--){
			if(lpar[x][i].f+z<thresh){
				z+=lpar[x][i].f;
				x=lpar[x][i].s;
				if(x==-1)return z;//arrived...
			}
		}
		z+=lpar[x][0].f;//should get it to just over thresh...
		x=lpar[x][0].s;
	}
	if(db)cerr<<x<<' '<<z<<' '<<ww[x]<<'\n';
	z+=ww[x];
	return z;
}

#include "park.h"
#include<bits/stdc++.h>
using namespace std;

static int place[1400],n;

static int r,r2;
static vector<int> avail;

void dnc(int a,int b,bool first=false){//find edges from node a to b...
	if(a>b)swap(a,b);
	//cerr<<"DNC "<<a<<' '<<b<<'\n';
	if(first){
		if(n==2)Answer(a,b);
		else{
			dnc(a,a+1);//picking any node works
			dnc(a+1,b);
		}
		return;
	}
	place[a]=place[b]=1;
	if(Ask(a,b,place)==1){
		//cerr<<"Ansewr "<<a<<' '<<b<<'\n';
		Answer(a,b);
		place[a]=place[b]=0;
	}else{
		int lo=0,hi=avail.size()-1,mid;
		for(int i=0;i<n;i++)place[i]=1;
		while(lo<hi){
			//cerr<<"check "<<lo<<' '<<hi<<":\t";
			mid=lo+((hi-lo)/2);
			for(int j=lo;j<=mid;j++){
				place[avail[j]]=0;
				//cerr<<r<<' ';
			}//cerr<<'\n';
			place[a]=place[b]=1;
			r=Ask(a,b,place);
			for(int j=lo;j<=mid;j++){
				place[avail[j]]=1;
			}
			if(r==1){//cos we need to find a node in between...
				lo=mid+1;
			}else{
				hi=mid;
			}
		}
		for(int i=0;i<n;i++)place[i]=0;

		mid=avail[lo];
		avail.erase(avail.begin()+lo);
		//cerr<<'\n';
		dnc(a,mid);
		dnc(mid,b);
	}
}

void Detect(int t, int N){
	n=N;
	avail.clear();
	for(int i=1;i+1<n;i++)avail.push_back(i);
	if(t==1){
		for(int i=0;i<n;i++){
			place[i]=1;
			for(int j=i+1;j<n;j++){
				place[j]=1;
				if(Ask(i,j,place)==1)Answer(i,j);
				place[j]=0;
			}
			place[i]=0;
		}
	}else if(t==2){
		dnc(0,n-1,true);
	}
}

/*int i;
for(i = 0 ; i < 2 ; i++) Place[i] = 0;
for(i = 2 ; i < N ; i++) Place[i] = 1;
if(Ask(3, 5, Place) != 1) return;
Answer(2, 4);
Answer(2, 5);
Answer(3, 4);
Place[0] = 1;
Place[3] = 0;
Place[5] = 0;
if(Ask(0, 4, Place) != 0) return;
Answer(0, 1);
Answer(0, 3);
Answer(1, 4);
Answer(1, 2);*/

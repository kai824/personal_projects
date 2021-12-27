// wires.cpp 23 Feb 19, 13:56:11 100 0.01 Judging completed in 10.66s on AWS Oregon.
#include "wires.h"
#include <bits/stdc++.h>
using namespace std;
void wire(int n, int P, int order[]){
	//cout<<'\n';
	int vp=1,hp=1,nex=0;//one for vertical, one for horizontal
	while(vp<=n && hp<=n){
	    if(press(vp,hp)==0){
	        order[nex]=1;
	        hp++;
	        nex++;
	    }else{
	        order[nex]=0;
	        nex++;
	        vp++;
	    }
	}
	if(vp>n){
	    for(int x=hp;x<=n;x++){
	        order[nex]=1;//since horizontal
	        nex++;
	    }
	}else if(hp>n){
	    for(int x=vp;x<=n;x++){
	        order[nex]=0;//vertical stuff
	        nex++;
	    }
	}
	//cout<<nex<<' '<<vp<<' '<<hp<<'\n';
	/*for(int x=0;x<n+n;x++){
		cout<<order[x];
		if(order[x]!=0 && order[x]!=1)cout<<"ur mom gay";
	}
	cout<<'\n';*/
}
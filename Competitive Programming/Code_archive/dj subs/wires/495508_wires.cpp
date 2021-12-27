// wires.cpp 23 Feb 19, 13:44:51 0 0 Judging completed in 9.1s on AWS Oregon.
#include "wires.h"
#include <bits/stdc++.h>

void wire(int n, int P, int order[]){
	int vp=1,hp=1,nex=0;//one for vertical, one for horizontal
	while(vp<=n && hp<=n){
	    if(press(vp,hp)==1){
	        order[nex]=hp;
	        hp++;
	        nex++;
	    }else{
	        order[nex]=vp;
	        nex++;
	        vp++;
	    }
	}
	if(vp==n){
	    for(int x=hp;x<=n;x++){
	        order[nex]=1;//since horizontal
	        nex++;
	    }
	}else{
	    for(int x=vp;x<=n;x++){
	        order[nex]=0;//vertical stuff
	    }
	}
}
// ans.cpp 10 Oct 19, 23:51:10 75 0.02 Judging completed in 3.873s on AWS Oregon.
#include <bits/stdc++.h>
#include "askonegetonefree.h"
using namespace std;
Answer guess(int n){
    int ans=INT_MAX,divide=0;
	for(int x=2;x<=n;x++){
	    if((int)(2*ceil(log2(n/x + (n%x!=0)))+x-1)<ans){
	        ans=(int)(2*ceil(log2(n/x + (n%x!=0)))+x-1);
	        divide=x;
	    }
	}
    Answer aa;
    int lop,hip,loq,hiq,t=n/divide,mid;
	lop=loq=0;
	hip=hiq=n-1;
    for(int x=1;x<divide;x++){
        aa=query(t*x);
        if(aa.p==1){//x>=t*x
			lop=t*x;
		}else{//x<t*x
			hip=min(hip,t*x-1);
		}
		if(aa.q==1){//x>=t*x
			loq=t*x;
		}else{//x<t*x
			hiq=min(hiq,t*x-1);
		}
    }
	while(lop==loq && hip==hiq && lop<hip){//same range
		mid=lop+hip - (lop+hip)/2;//round up
		aa=query(mid);
		if(aa.p==1){//x>=t*x
			lop=mid;
		}else{//x<t*x
			hip=mid-1;
		}
		if(aa.q==1){//x>=t*x
			loq=mid;
		}else{//x<t*x
			hiq=mid-1;
		}
	}
	while(lop<hip){
		mid=lop+hip - (lop+hip)/2;//round up
		aa=query(mid);
		if(aa.p==1){//x>=t*x
			lop=mid;
		}else{//x<t*x
			hip=mid-1;
		}
	}
	while(loq<hiq){
		mid=loq+hiq - (loq+hiq)/2;//round up
		aa=query(mid);
		if(aa.q==1){//x>=mid
			loq=mid;
		}else{//x<t*x
			hiq=mid-1;
		}
	}
	aa.p=lop;aa.q=loq;
    return aa;
}
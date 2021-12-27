// middlenumber.cpp 31 Jan 19, 23:46:24 0 0 Compilation failed on AWS Oregon.
#include "middlenumber.h"
#include<bits/stdc++.h>
using namespace std;
int num=0;
unordered_map<int,int> ft;//sparse fenwick
inline int ls(int x){
	return(x & (-x));
}
inline int query(int p){//sum of first p elements
	int sum=0;
	for(;p;p-=ls(p)){
	    if(ft.find(p)==ft.end())ft[p]=0;
	    sum+=ft[p];
	}
	return sum;
}
inline void update(int p,int v){
	for(;p>0;p+=ls(p)){//p>0 since it will be negative once overflow
	    if(ft.find(p)==ft.end())ft[p]=0;
		ft[p]+=v;//n is the number of elements
	}
}

int get_num(int a){//find the ath element 1-indexed
    int lo,hi,mid;
    lo=0;hi=INT_MAX;
    while(lo<hi){
        mid=(hi-lo)/2 + lo;
        if(query(mid)<a)lo=mid+1;
        else hi=mid;
    }
    return lo;
}
inline int get_median(){
    if((num%2)==1){
        return get_num(num/2 + 1);
    }else{
        int a=get_num(num/2), b=get_num(num/2 + 1);
        return ((b-a)/2)+a;
    }
}

int init(int* arr, int length) {
    for(int x=0;x<length;x++){
        update(arr[x],1);
    }
    num=length;
    return get_median();
}

int add_number(int x) {
    update(x,1);
    num++;
    return get_median();
}

int remove_number(int x) {
    update(x,-1)
    num--;
    return get_median();
}

int change_number(int oldx, int newx) {
    update(oldx,-1);
    update(newx,-1);
    return get_median();
}
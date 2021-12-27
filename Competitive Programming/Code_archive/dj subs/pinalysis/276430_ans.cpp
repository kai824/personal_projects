// ans.cpp 3 Dec 17, 15:56:09 100 0.05 Judging completed in 4.751s on AWS Oregon.
#include "pinalysis.h"
using namespace std;
int fts[15][100005],n=100004,max_updated=0;
int ls(int x){
	return(x & (-x));
}
int query(int p,int f) {
    //returns sum of first p elements on fenwick f
	int sum = 0;
	for(; p; p -= ls(p))sum+=fts[f][p];
	return sum;
}
void update(int p, int v,int f) {
	for(; p <= n; p += ls(p)){
		fts[f][p]+=v;//n is the number of elements
	}
}
int countDigit(int S, int E, int D) {
    if(max_updated<E){
        //update fenwick trees...
        for(int x=max_updated+1;x<=E;x++){
            update(x,1,getDigit(x));
        }
        max_updated=E;
    }
    return(query(E,D)-query(S-1,D));
}
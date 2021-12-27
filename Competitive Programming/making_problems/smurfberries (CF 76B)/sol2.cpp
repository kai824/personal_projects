#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
 
using namespace std;
 
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
 
int xm[100100],M;
int xc[100100],C;
int Y1,Y2;
int mark[100100];
int main() {
	scanf("%d%d%d%d",&M,&C,&Y1,&Y2);
	FOR(i,0,M)scanf("%d",xm+i);
	FOR(i,0,C)scanf("%d",xc+(i+1));
	if(C==0){
		cout << M << endl;
		return 0;
	}
	xc[0]=-200000000;
	xc[C+1]=200000000;
//	FOR(i,0,C+2)cout << xc[i] << " ";
//	cout << endl;
//	FOR(i,0,M)cout << xm[i] << " ";
//	cout << endl;
	memset(mark,0,sizeof(mark));
	int cid=0;
	int res = M;
	FOR(m,0,M){
		int cdist = abs(xm[m]-xc[cid]);
		int ndist;
		while(true){
			ndist = abs(xm[m]-xc[cid+1]);
			if(ndist>=cdist)break;
			cdist = ndist;
			cid++;
		}
		if(mark[cid]==0){
			res--;
			mark[cid]=cdist+1;
		} else if(mark[cid]==cdist+1){
			res--;
		} else if(ndist==cdist){
			mark[cid+1]=cdist+1;
			res--;
		} else {
			mark[cid]=min(mark[cid],cdist+1);
		}
	}
//	FOR(i,0,C)cout << mark[i] << " ";
	cout << res << endl;
	return 0;
}




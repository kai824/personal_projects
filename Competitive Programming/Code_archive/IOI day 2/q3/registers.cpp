#include "registers.h"
#include<bits/stdc++.h>
using namespace std;

#define lint long long
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair


void construct_instructions(int s, int n, int k, int q) {
	assert(s==0);
	vector<bool> vv;
	vv.resize(2000);
	for(int i=0;i<2000;i++)vv[i]=0;
	vv[0]=1;
	if(k==1){
		append_move(1,0);
		append_right(1,1,1);
		append_and(0,0,1);
	}else{
		//we have: pqrs stored...
		append_right(1,0,3);//...p
		append_left(2,0,2000-2);//rs...
		append_right(3,2,1999);//...r
		append_xor(4,1,3);
		append_left(5,4,1);
		append_add(4,4,5);//...p^r (2-bit)
		append_not(5,4);//...!(p^r) (2-bit)

		// append_left(6,0,1999);
		// append_right(6,6,1999);//s
		append_left(7,0,1997);//q
		append_right(7,7,1999);

		append_and(8,0,7);
		append_left(9,1,1);//..p0
		append_add(9,9,8);
		append_and(10,5,9);//15 so far...

		append_and(11,0,1);//p&s
		append_not(12,1);//!p
		append_and(12,12,7);//(!p)&q
		append_or(13,11,12);
		append_and(15,13,4);
		append_add(0,10,15);
	}
}

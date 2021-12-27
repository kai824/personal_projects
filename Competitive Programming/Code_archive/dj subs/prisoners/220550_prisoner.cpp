// prisoner.cpp 21 Sep 17, 09:27:42 100 0 Judging completed in 9.028s on AWS Oregon.
#include "prisoner.h"
#include<bits/stdc++.h>
using namespace std;
void prisoner(int n, int id){
    int a=openBox(id),b=id;
	while(a!=id){
	    b=a;a=openBox(a);
	}
}
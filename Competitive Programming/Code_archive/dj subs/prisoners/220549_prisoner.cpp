// prisoner.cpp 21 Sep 17, 09:07:45 38.5 0 Judging completed in 11.338s on AWS Oregon.
#include "prisoner.h"
#include<bits/stdc++.h>
using namespace std;
void prisoner(int n, int id){
    int a=openBox(id),b=id;
	while(a!=id){
	    b=a;a=openBox(a);
	}
}
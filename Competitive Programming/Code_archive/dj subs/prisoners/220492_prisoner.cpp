// prisoner.cpp 20 Sep 17, 09:18:04 0 0 Compilation failed on AWS Oregon.
#include "prisoner.h"
#include<bits/stdc++.h>
using namespace std;
void prisoner(int n, int id){
    int a=openBox(id),b=id;
	while(a!=id){
	    b=a;a=openBox(a);
	}
}
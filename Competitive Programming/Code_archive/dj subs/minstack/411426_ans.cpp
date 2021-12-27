// ans.cpp 12 Nov 18, 21:54:09 100 1.11 Judging completed in 6.022s on AWS Oregon.
#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;
vector<int>a,b;
void push(int x) {
    if(b.size()==0)b.push_back(x);
    else b.push_back(min(x,b.back()));
	a.push_back(x);
}

void pop() {
	a.pop_back();
	b.pop_back();
}

int top() {
	return(a.back());
}

int getMin() {
	return(b.back());
}
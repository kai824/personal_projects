// ans.cpp 10 Oct 17, 09:17:57 100 1.24 Judging completed in 8.816s on AWS Oregon.
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
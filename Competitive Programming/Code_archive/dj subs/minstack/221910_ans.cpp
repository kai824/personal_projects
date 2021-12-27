// ans.cpp 9 Oct 17, 22:28:49 0 0.01 Judging completed in 6.539s on AWS Oregon.
#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;
vector<int>a,b;
void push(int x) {
    b.push_back(min(x,b.back()));
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
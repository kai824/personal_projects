// ans.cpp 9 Oct 17, 22:29:35 0 0 Judging completed in 6.534s on AWS Oregon.
#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;
stack<int>a,b;
void push(int x) {
    b.push(min(x,b.top()));
	a.push(x);
}

void pop() {
	a.pop();
	b.pop();
}

int top() {
	return(a.top());
}

int getMin() {
	return(b.top());
}
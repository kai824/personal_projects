// ans.cpp 11 Mar 17, 22:34:05 15 2 Judging completed in 9.769s on AWS Ireland.
#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;

vector<int> v,v2;

void push(int x) {
	v.push_back(x);
}

void pop() {
	v.pop_back();
}

int top() {
	return v.back();
}

int getMin() {
	v2=v;
	sort(v2.begin(),v2.end());
	return v2[0];
}
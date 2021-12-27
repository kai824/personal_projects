// reverse.cpp 12 Nov 16, 09:19:28 100 0.02 Judging completed in 4.794s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;

vector<long long> reverse (vector<long long> a) {
    vector<long long> b;
    int d=a.size();
    for(uint64_t c=0;c<d;c++){
        b.push_back(a[a.size()-1]);
        a.pop_back();
    }
	return b;
}
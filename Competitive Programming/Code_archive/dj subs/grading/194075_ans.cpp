// ans.cpp 24 Feb 17, 12:01:03 0 0 Compilation failed on AWS Ireland.
#include "grading.h"
#include <bits/stdc++.h>
using namespace std;

string gradeMin(int N, int A[]) {
    int a,b,c;
    startTime();
    a=findmin(N,A);
    b=stopTime();
    if(b>=500) return "Time Limit Exceeded";
    c=INT_MAX;
    for(int x=0;x<N;x++){
        c=min(c,A[x]);
    }
    if(a!=c)return "Wrong Answer";
    return "Accepted";
}
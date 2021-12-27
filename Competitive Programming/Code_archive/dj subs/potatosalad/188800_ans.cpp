// ans.cpp 8 Feb 17, 19:03:07 100 0.03 Judging completed in 6.069s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,d,a;
    priority_queue<int> b;
    cin>>n>>d;
    for(int x=0;x<n;x++){
        cin>>a;
        b.push(a);
    }a=0;//now used as ans...
    for(int x=0;x<d;x++){
        a+=b.top();
        b.pop();
    }cout<<a;
    return 0;
}
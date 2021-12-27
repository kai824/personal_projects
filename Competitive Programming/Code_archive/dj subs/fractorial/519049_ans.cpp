// ans.cpp 28 Apr 19, 14:15:34 100 0.01 Judging completed in 3.651s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("fractorial.in");
    ofstream out("fractorial.out");
    long long n,cur=1,nex=1;
    in>>n;
    while(true){
        cur*=nex;
        cur%=n;
        if(cur==0)break;
        nex++;
    }
    out<<nex;
    return 0;
}
// ans.cpp 31 May 17, 16:06:50 90 0 Judging completed in 4.627s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){//take starting time as 11-11 11 11
    int d,h,m,mins=0;
    cin>>d>>h>>m;
    d-=11;
    h-=11;
    m-=11;
    mins+=m;
    mins+=h*60;
    mins+=d*24*60;
    cout<<mins;
    return 0;
}
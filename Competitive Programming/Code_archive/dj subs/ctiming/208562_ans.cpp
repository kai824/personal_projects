// ans.cpp 31 May 17, 16:10:44 100 0 Judging completed in 3.939s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){//take starting time as 11-11 11 11
    int d,h,m,mins;
    cin>>d>>h>>m;
    d-=11;
    h-=11;
    m-=11;
    mins=m;
    mins+=h*60;
    mins+=d*24*60;
    if(mins<0){
        cout<<-1;
        return 0;
    }
    cout<<mins;
    return 0;
}
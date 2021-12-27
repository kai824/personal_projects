// ans.cpp 12 Aug 17, 22:17:46 100 0 Judging completed in 5.221s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int d,h,m,sum=0;
    cin>>d>>h>>m;
    sum+=(d-11)*1440;
    sum+=(h-11)*60;
    sum+=m-11;
    if(sum<0) cout<<"-1"<<endl;
    else cout<<sum<<endl;
}
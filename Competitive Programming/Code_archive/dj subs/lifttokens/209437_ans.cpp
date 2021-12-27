// ans.cpp 5 Jun 17, 21:23:36 10 0 Judging completed in 5.42s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int stuff[10]={10000,5000,1000,500,100,50,17,10,5,1},it=0,n,cost=0;
    cin>>n;
    while(n>0){
        cost+=n/(stuff[it]);
        n%=stuff[it];
        it++;
    }
    cout<<cost;
    return 0;
}
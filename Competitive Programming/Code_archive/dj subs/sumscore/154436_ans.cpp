// ans.cpp 23 Oct 16, 20:33:28 100 0.01 Judging completed in 4.484s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int sum=0,a;
    while(a!=-1){
        cin>>a;
        if (a==-1) break;
        sum=sum+a;
    }
    cout<<sum;
    return 0;
}
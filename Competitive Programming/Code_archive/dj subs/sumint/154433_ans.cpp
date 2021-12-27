// ans.cpp 23 Oct 16, 20:29:55 100 0 Judging completed in 5.005s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,sum=0,d;
    cin>>a;
    for(int c=1;c<=a;c++){
        cin>>d;
        sum=sum+d;
    }
    cout<<sum;
    return 0;
}
// ans.cpp 11 Feb 17, 12:35:45 20 0 Judging completed in 4.859s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b=0;
    cin>>a;
    while(b>2){
        a/=2;
        b++;
    }
    cout<<b;
    return 0;
}
// ans.cpp 17 Dec 16, 09:35:47 0 1 Judging completed in 8.51s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    int b[a];
    for(int x=0;x<a;x++){
        cin>>b[x];
    }
    a=0;
    for(int x=0;x<a;x++){
        if((x==0 || b[x]>=b[x-1])&&(x==a-1 || b[x]>=b[x+1]))a++;
    }
    cout<<a;
    return 0;
}
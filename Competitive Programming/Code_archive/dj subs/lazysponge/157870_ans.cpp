// ans.cpp 2 Nov 16, 11:46:31 100 0.01 Judging completed in 5.886s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d,e;
    cin>>a>>b;
    for(c=1;c<=a;c=c+1){
        cin>>d;
        if(c==b) e=d;
    }
    cout<<e;
    return 0;
}
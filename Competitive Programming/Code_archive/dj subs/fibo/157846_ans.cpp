// ans.cpp 2 Nov 16, 09:55:17 2.5 0 Judging completed in 13.823s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d,prev=0,current=1;
    cin>>a>>b;
    if(a==1) cout<<0;
    else if(a==2) cout<<1;
    else{
        for(c=2;c<a;c=c+1){
            d=current;
            current=prev+current;
            prev=d;
        }
        cout<<(d%b);
    }
    return 0;
}
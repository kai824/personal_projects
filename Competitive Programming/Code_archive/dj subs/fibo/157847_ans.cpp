// ans.cpp 2 Nov 16, 10:08:07 100 0 Judging completed in 6.876s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d,prev=0,current=1;
    cin>>a>>b;
    if(a==0) cout<<0;
    else if(a==1) cout<<1;
    else{
        for(c=2;c<=a;c=c+1){
            d=current;
            current=prev+current;
            prev=d;
            prev=prev%b;
            current=current%b;
        }
        cout<<(current%b);
    }
    return 0;
}
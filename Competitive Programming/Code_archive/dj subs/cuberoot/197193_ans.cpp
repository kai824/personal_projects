// ans.cpp 6 Mar 17, 12:42:02 20 1 Judging completed in 5.487s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cube(int x){
    return(x*x*x);
}
int main() {
    uint64_t a,b,lo,mid,hi,c;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        lo=0;
        hi=1000005;
        while(lo<hi){
            mid=(lo+hi)/2;
            c=cube(mid);
            if(c==b){
                cout<<mid<<endl;
                break;
            }if(c<b)lo=mid;
            else hi=mid;
        }
    }
    return 0;
}
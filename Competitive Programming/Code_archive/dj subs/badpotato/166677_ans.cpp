// ans.cpp 2 Dec 16, 17:39:11 100 0.12 Judging completed in 5.662s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,cur=0,max_h=0;
    cin>>a;
    for(int c=0;c<a;c++){
        cin>>b;
        if(b==-1) cur=0;
        else{
            cur+=b;
            max_h=max(max_h,cur);
        }
    }
    cout<<max_h;
    return 0;
}
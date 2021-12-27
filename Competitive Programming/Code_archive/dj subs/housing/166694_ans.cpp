// ans.cpp 2 Dec 16, 18:07:11 100 0 Judging completed in 3.429s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int m(int n,int limit){
    if(n<limit) return 0;
    int ans=1,b;
    for(int a=limit;a<n;a++){
        b=m(n-a,a);
        if(b==0) break;
        else ans += b;
    }
    return ans;
}
int main() {
    int a;
    cin>>a;
    cout<<m(a,5);
    return 0;
}
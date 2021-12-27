// ans.cpp 31 Dec 19, 18:02:51 0 0.06 Judging completed in 4.667s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a,b;
    cin>>n>>k;
    set<int> ss;
    for(int x=0;x<n;x++){
        cin>>a;
        ss.insert(a);
    }
    while(k>0 && *ss.begin()*2<*ss.rbegin()){
        a=*ss.begin();
        ss.erase(ss.begin());
        ss.insert(a*2);
        k--;
    }
    b=k%n;
    if(b==0)b=n;
    k-=b;
    for(int x=1;x<k%n;x++){
        ss.erase(ss.begin());
    }
    a=*ss.begin();
    for(int x=0;x<=k/n;x++){
        a*=2;
        a%=1000000007;
    }
    cout<<a;
    return 0;
}
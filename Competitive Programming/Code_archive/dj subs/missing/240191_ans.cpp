// ans.cpp 4 Nov 17, 10:23:09 100 0.22 Judging completed in 7.039s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long sums[15],sums2[15],n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        for(int y=0;y<a.length();y++){
            sums[y]+=(int) a[y];
        }
    }
    for(int x=0;x<n-1;x++){
        cin>>a;
        for(int y=0;y<a.length();y++){
            sums2[y]+=(int) a[y];
        }
    }
    a="";
    for(int x=0;x<15;x++){
        if(sums[x]==sums2[x])break;
        a=a+" ";
        a[a.length()-1]=(char) (sums[x]-sums2[x]);
    }
    cout<<a;
    return 0;
}
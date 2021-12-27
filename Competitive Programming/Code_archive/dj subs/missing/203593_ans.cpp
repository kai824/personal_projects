// ans.cpp 5 Apr 17, 21:00:04 100 1.22 Judging completed in 9.236s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
long long sums[15],sums2[15],n;
int main() {
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
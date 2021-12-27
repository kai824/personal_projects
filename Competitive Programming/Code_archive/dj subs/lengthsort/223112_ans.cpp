// ans.cpp 17 Oct 17, 20:51:56 40 0.45 Judging completed in 6.954s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string,int>a,pair<string,int> b){
    return(a.first.length()>b.first.length());
}
int main() {
    int n;
    cin>>n;
    pair<string,int> a[n];
    for(int x=0;x<n;x++){
        cin>>a[x].first;
        a[x].second=a[x].first.length();
    }
    sort(a,a+n,cmp);
    for(int x=0;x<n;x++){
      cout<<a[x].first<<endl;
    }
    return 0;
}
// ans.cpp 23 Sep 17, 09:55:58 100 1.22 Judging completed in 12.905s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct a{
    char x[21];
};
bool cmp(pair<unsigned int,a> x,pair<unsigned int,a> y){
    return(x.first<y.first);
}
int main() {
    unsigned int n;
    cin>>n;
    pair<unsigned int,a> arr[n];
    for(unsigned int x=0;x<n;x++){
        cin>>arr[x].second.x;
    }
    for(unsigned int x=0;x<n;x++){
        cin>>arr[x].first;
    }
    sort(arr,arr+n,cmp);
    for(unsigned int x=0;x<n;x++){
        cout<<arr[x].second.x<<'\n';
    }
    return 0;
}
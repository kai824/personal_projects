// ans.cpp 28 Oct 17, 13:01:56 100 0.49 Judging completed in 9.33s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct a{
    char x[21];
};
bool cmp(pair<unsigned int,a> x,pair<unsigned int,a> y){
    return(x.first<y.first);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
// ans.cpp 21 Oct 17, 10:35:53 100 0.37 Judging completed in 5.922s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i;
    cin>>i;
    int arr[i];
    for(int x=0;x<i;x++){
        cin>>arr[x];
    }
    sort(arr,arr+i,cmp);
    for(int x=0;x<i;x++){
        cout<<arr[x]<<'\n';
    }
    return 0;
}
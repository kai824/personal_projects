// ans.cpp 21 Oct 17, 10:35:25 100 0.98 Judging completed in 6.635s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
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
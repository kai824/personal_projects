// ans.cpp 1 Jan 19, 20:22:25 0 0.01 Judging completed in 2.615s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[70],nex_it=0;
    while(cin>>arr[nex_it]){
        nex_it++;
    }
    while(nex_it--){
        cout<<arr[nex_it]<<'\n';
    }
    return 0;
}
// ans.cpp 1 Jan 19, 21:04:33 0 0.01 Judging completed in 2.979s on AWS Oregon.
#include <iostream>
using namespace std;
int main() {
    long long arr[70],nex_it=0;
    while(cin>>arr[nex_it]){
        nex_it++;
    }
    while(nex_it--){
        cout<<arr[nex_it]<<'\n';
    }
    return 0;
}
// ans.cpp 1 Jan 19, 20:59:49 0 0.01 Judging completed in 2.929s on AWS Oregon.
#include <iostream>
using namespace std;
int main() {
    short int arr[1000000],nex_it=0;
    while(cin>>arr[nex_it]){
        nex_it++;
    }
    while(nex_it--){
        cout<<arr[nex_it]<<'\n';
    }
    return 0;
}
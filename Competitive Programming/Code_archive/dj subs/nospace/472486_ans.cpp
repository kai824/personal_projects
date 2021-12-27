// ans.cpp 1 Jan 19, 20:59:31 0 0.02 Judging completed in 2.809s on AWS Oregon.
#include <iostream>
using namespace std;
int main() {
    short int arr[10000],nex_it=0;
    while(cin>>arr[nex_it]){
        nex_it++;
    }
    while(nex_it--){
        cout<<arr[nex_it]<<'\n';
    }
    return 0;
}
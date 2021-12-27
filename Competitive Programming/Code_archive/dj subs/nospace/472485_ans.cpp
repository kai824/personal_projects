// ans.cpp 1 Jan 19, 20:59:14 0 0.02 Judging completed in 2.524s on AWS Oregon.
#include <iostream>
using namespace std;
int main() {
    short int arr[70],nex_it=0;
    while(cin>>arr[nex_it]){
        nex_it++;
    }
    while(nex_it--){
        cout<<arr[nex_it]<<'\n';
    }
    return 0;
}
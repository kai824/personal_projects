// ans.cpp 1 Jan 19, 21:00:05 0 0.03 Judging completed in 4.856s on AWS Oregon.
#include <iostream>
using namespace std;
int main() {
    short int arr[1000005],nex_it=0;
    while(cin>>arr[nex_it]){
        nex_it++;
    }
    while(nex_it--){
        cout<<arr[nex_it]<<'\n';
    }
    return 0;
}
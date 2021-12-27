// ans.cpp 1 Jan 19, 21:00:41 0 0.01 Judging completed in 2.79s on AWS Oregon.
#include <iostream>
using namespace std;
int main() {
    short int arr[300005],nex_it=0;
    while(cin>>arr[nex_it]){
        nex_it++;
    }
    while(nex_it--){
        cout<<arr[nex_it]<<'\n';
    }
    return 0;
}
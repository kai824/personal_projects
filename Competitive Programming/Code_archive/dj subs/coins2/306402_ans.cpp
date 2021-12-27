// ans.cpp 26 Dec 17, 14:57:04 100 1.87 Judging completed in 6.807s on AWS Oregon.
#include<iostream>
#include<bitset>
using namespace std;
bitset<30000005>arr;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,Q;cin>>N>>Q;
    while(Q--){
        int a,b;cin>>a>>b;
        arr[a]=!arr[a];
        arr[b+1]=!arr[b+1];
    }
    bool curr=0;
    for(int i=0;i<N;++i){
        curr^=arr[i];
        cout<<curr;
    }
}
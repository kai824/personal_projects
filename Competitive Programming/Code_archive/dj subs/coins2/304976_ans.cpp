// ans.cpp 25 Dec 17, 15:32:37 100 1.86 Judging completed in 6.504s on AWS Oregon.
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
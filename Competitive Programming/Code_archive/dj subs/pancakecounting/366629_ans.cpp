// ans.cpp 26 May 18, 12:57:18 0 0 Judging completed in 2.325s on AWS Oregon.
#include <bitset>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    bitset<10000100>arr;
    int n,k,a;
    cin>>n;
    return 0;
    for(int x=0;x<n;x++){
        cin>>a;
        for(int y=0;y<10;y++){
            if(((1<<y)&a)!=0){
                arr[x*10 + y]=1;
            }else arr[x*10 + y]=0;
        }
    }
    cin>>k;
    for(int x=0;x<n;x++){
        a=0;
        for(int y=0;y<10;y++){
            if(arr[x*10 + y]==1){
                a+=(1<<y);
            }
        }
        cout<<a+k<<'\n';
    }
    return 0;
}
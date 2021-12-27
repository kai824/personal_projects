// ans.cpp 26 May 18, 13:01:57 0 0.08 Judging completed in 2.911s on AWS Oregon.
#include <bitset>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a;
    cin>>n;
    bitset<10000100>arr;
    for(int x=0;x<n;x++){
        cin>>a;
        for(int y=0;y<10;y++){
            /*if(((1<<y)&a)!=0){
                //arr[(x*10) + y]=1;
            }*/
        }
    }
    cin>>k;
    return 0;
    for(int x=0;x<n;x++){
        a=0;
        for(int y=0;y<10;y++){
            if(arr[(x*10) + y]==1){
                a+=(1<<y);
            }
        }
        cout<<a+k<<'\n';
    }
    return 0;
}
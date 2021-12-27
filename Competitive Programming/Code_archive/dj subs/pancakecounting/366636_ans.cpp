// ans.cpp 26 May 18, 13:00:39 0 0 Compilation failed on AWS Oregon.
#include <bitset>
#include <iostream>
using namespace std;
bitset<10000100>arr;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        for(int y=0;y<10;y++){
            if(((1<<y)&a)!=0){
                arr[(x*10) + y]=1;
            }else //;
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
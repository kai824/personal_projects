// ans.cpp 19 May 17, 21:56:02 50 0.01 Judging completed in 7.953s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
    int a[n+5];
    a[0]=-1;
    for(int x=1;x<=n;x++){
        for(int y=1;(true);y++){
            if(y*2<a[x-y]){
                a[x]=y;
                break;
            }
            if(y*3>=x){
                a[x]=x;
                break;
            }
        }
    }
    cout<<a[n];
    return 0;
}
// ans.cpp 21 May 17, 12:32:38 50 0 Judging completed in 4.789s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
    if(n>2092500){
        cout<<n;
        return 0;
    }
    int a[2092501];
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